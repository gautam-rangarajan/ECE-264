#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "answer05.h"

#define FALSE 0
#define TRUE 1

Image * Image_load(const char * filename)
{

    FILE * fp = NULL;
    size_t read;
//    BMP_Header header;
    Image * tmp_im = NULL, * im = NULL;
//    size_t n_bytes = 0;
    int err = FALSE;

    ///DECLARING NEW VARIABLES
        ImageHeader header;

    if(!err) { // Open filename
	fp = fopen(filename, "rb");
	if(!fp) {
	    printf( "Failed to open file '%s'\n", filename);
	    err = TRUE;
	}
    }

    if(!err) { // Read the header
	read = fread(&header, sizeof(ImageHeader), 1, fp);
	if(read != 1) {
	    printf( "Failed to read header from '%s'\n", filename);
	    err = TRUE;
	}
    }



    //MAKING SURE THE HEADER IS CORRECT
    if(!err && header.magic_number != ECE264_IMAGE_MAGIC_NUMBER){
        err = TRUE;
    }

    if(!err && header.width <= 0){
        err = TRUE;
    }

    if(!err && header.height <= 0){
        err = TRUE;
    }

    if(!err && header.comment_len <= 0){
        err = TRUE;
    }


//VARIABLE THAT CONTAINS NUMBER OF PIXELS
    int pixCnt = header.height * header.width;

//ALLOCATING SPACE FOR THE IMAGE,COMMENT AND PIXELS

    if(!err) { // Allocate Image struct
	tmp_im = malloc(sizeof(Image));
	if(tmp_im == NULL) {
	    printf( "Failed to allocate im structure\n");
	    err = TRUE;
	}

	if(!err){
	tmp_im -> comment = malloc(sizeof(char) * header.comment_len);
	tmp_im -> data = malloc(sizeof(uint8_t) * pixCnt);
    if (tmp_im->data == NULL){
        free(tmp_im->comment); // Remember, you can always free(NULL)
        free(tmp_im->data);
        free(tmp_im);
        fclose(fp);
        return NULL;
	}
    if (tmp_im->comment == NULL){
        free(tmp_im->comment); // Remember, you can always free(NULL)
        free(tmp_im->data);
        free(tmp_im);
        fclose(fp);
        return NULL;
	}
    }

    }

        if(!err) { // Init the Image struct
	tmp_im->width = header.width;
	tmp_im->height = header.height;
    }
    //MAKING SURE THE COMMENTS ARE READ, AND END WITH '\0'

    if(!err){
        read = fread(tmp_im->comment, sizeof(char), header.comment_len, fp);
        if(read !=  header.comment_len){    //------check------
            err = TRUE;
            free(tmp_im->comment); // Remember, you can always free(NULL)
            free(tmp_im->data);
            free(tmp_im);
            fclose(fp);
            return NULL;
        }
    }

    if(!err && tmp_im->comment[header.comment_len - 1] != '\0'){
        err = TRUE;
    }

//READING THE PIXELS

    int curPosn;
    if(!err){
        read = fread(tmp_im->data, sizeof(char), pixCnt, fp);
        if(read != pixCnt){
            err = TRUE;
            free(tmp_im->comment); // Remember, you can always free(NULL)
            free(tmp_im->data);
            free(tmp_im);
            fclose(fp);
            return NULL;
        }
        }

    if(!err){

     curPosn = ftell(fp);
     fseek(fp, 0, SEEK_END);
     if(curPosn != ftell(fp)){
         err = TRUE;
     }
    }


    if(!err) { // We're winners...
	im = tmp_im;  // bmp will be returned
	tmp_im = NULL; // and not cleaned up
    }

    // Cleanup

    if(tmp_im != NULL) {
	free(tmp_im->comment); // Remember, you can always free(NULL)
	free(tmp_im->data);
	free(tmp_im);
    }
    if(fp) {
	fclose(fp);
    }


    return im;

    }


int Image_save(const char * filename, Image * image)
{
    FILE * fp = NULL;
    int err;
    err = FALSE;
    size_t read;


    fp = fopen(filename, "wb");
    if(fp == NULL){
        err = TRUE;
    }

    ImageHeader header;
    header.magic_number = ECE264_IMAGE_MAGIC_NUMBER;
    header.width = image->width;
    header.height = image->height;
    header.comment_len = strlen(image->comment) + 1;

    if(!err){
        read = fwrite(&header, sizeof(ImageHeader), 1, fp);
         if(read !=  1){    //------check------
            err = TRUE;
        }
    }


    if(!err){
        read = fwrite(image->comment, sizeof(char), header.comment_len, fp);
        if(read !=  header.comment_len){    //------check------
            err = TRUE;
        }
    }

    int pixCnt = header.height * header.width;

     if(!err){
        read = fwrite(image->data, sizeof(uint8_t), pixCnt, fp);

        if(read != pixCnt){
            err = TRUE;
        }
     }

    if(fp){
        fclose(fp);
    }

   return (!err);
}


void Image_free(Image * image)
{
    if(image != NULL){
        free(image->comment);
        free(image->data);
        free(image);
    }
}

void linearNormalization(int width, int height, uint8_t * intensity)
{
	int count = 1;
	int min = intensity[0];
	int max = intensity[0];
	int count1 = 0;

	while(count < width * height){

    	if(intensity[count] < min){
	    min = intensity[count];
    	}

    	if(intensity[count] > max){
	    max = intensity[count];
    	}

    	count++;
	}


	while(count1 < width*height){
	    intensity[count1] = (intensity[count1] - min) * 255 / (max - min);
	    count1++;
	}
}
