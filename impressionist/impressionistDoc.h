// 
// impressionistDoc.h
//
// header file for Doc 
//

#ifndef ImpressionistDoc_h
#define ImpressionistDoc_h

#include "impressionist.h"
#include "bitmap.h"
#include <stdlib.h>

class ImpressionistUI;

class ImpressionistDoc 
{
public:
	ImpressionistDoc();

	void	setUI(ImpressionistUI* ui);		// Assign the UI to use

	int		loadImage(char *iname);			// called by the UI to load image
	int		saveImage(char *iname);			// called by the UI to save image
    
    int		loadAnotherImage(char *iname);			// called by the UI to load another image
    int		loadBlackAndWhiteImage(char *iname);			// called by the UI to load another image
    int		loadAlphaMapImage(char *iname);			// called by the UI to load another image


	int     clearCanvas();                  // called by the UI to clear the drawing canvas
    int     autoPaint();                  //  called by the UI to auto paint

    int     coarseToFinePainting();
    
	void applyFilter( const unsigned char* sourceBuffer, //The filter kernel
		int srcBufferWidth, int srcBufferHeight,
		unsigned char* destBuffer,
		const double *filterKernel, 
		int knlWidth, int knlHeight, 
		double divisor, double offset );
    
    void edgeDetector( const unsigned char* sourceBuffer, //The filter kernel
                     int srcBufferWidth, int srcBufferHeight,
                     unsigned char* destBuffer,
                     const double *filterKernel1,
                     const double *filterKernel2,
                     int knlWidth, int knlHeight);
    
    // The grayscale image
    void grayscaleImage( const unsigned char* sourceBuffer, unsigned char* destBuffer, int srcBufferWidth, int srcBufferHeight);

	void	setBrushType(int type);			// called by the UI to set the brushType
	int		getSize();						// get the UI size
	void	setSize(int size);				// set the UI size
    Point   getViewPaintCursorPosition();
    
    float		getAlpha();						// get the UI alpha
    void	setApha(float alpha);				// set the UI alpha
    
    int		getLineWidth();						// get the UI lineWidth
    void	setLineWidth(int lineWidth);		// set the UI lineWidth
    
    int		getLineAngle();						// get the UI lineAngle
    void	setLineAngle(int lineAngle);		// set the UI lineAngle
    
    bool		getMultiColor();				// get the UI multi color
    bool		getEdgeClipping();				// get the UI edge clipping
    bool		getAnotherEdgeClipping();				// get the UI edge clipping
    bool		getAnotherGradient();			// get the UI another gradient
    
    
    bool		getColorBlending();						// get the UI size
    
    
	char*	getImageName();					// get the current image name
    char*	getAnotherImageName();					// get the current image name
    char*	getBlackAndWhiteImageName();					// get the current image name
    char*	getAlphaMapImageName();					// get the current image name
    
    
    int     checkEdge(int targetX, int targetY);
    
    void	getEdgeImage();         // store edge image in m_ucEdgeImage
    void    getGrayscaleImage();    // store grayscale image in m_ucGrayscale Image
    
    void    freePreviewBackup(unsigned char* backup);
    void    mallocPreviewBackup(unsigned char* backup);
    
   // int     previewPaintView(unsigned char* previewBackup);

// Attributes
public:
	// Dimensions of original window.
	int				m_nWidth, 
					m_nHeight;
	// Dimensions of the paint window.
	int				m_nPaintWidth, 
					m_nPaintHeight;
    
    // Dimensions of another image.
    int				m_nAnotherImageWidth, m_nAnotherImageHeight;
    // Dimensions of black and white image.
    int				m_nBlackAndWhiteImageWidth, m_nBlackAndWhiteImageHeight;
    
    // Dimensions of another image.
    int				m_nAlphaMapImageWidth, m_nAlphaMapImageHeight;

    
    
	// Bitmaps for original image and painting.
    
	unsigned char*	m_ucBitmap;
	unsigned char*	m_ucPainting;
    unsigned char*	m_ucEdgeImage;
    unsigned char*	m_ucGrayscaleImage;
    unsigned char*	m_ucAnotherImage;
    unsigned char*	m_ucBlackAndWhiteImage;
    unsigned char*	m_ucAlphaMapImage;
    

	// Used by the filtering code so that we can
	// preview filters before applying.
    unsigned char*	m_ucEdgeImageBackup;
    unsigned char*	m_ucEdgeImageBackup2;
	unsigned char*	m_ucPreviewBackup;
    unsigned char*	m_ucPreviewBackup2;
    unsigned char*  m_ucTempPointer;
    
    
    
    
  //  unsigned char*	m_ucSecondImage;
    
    //if the images have generated
    bool hasEdgeImage;
    bool hasGrayscaleImage;
    bool hasAnotherImage;
    bool hasBlackAndWhiteImage;
    bool hasAlphaMapImage;
    
	// The current active brush.
	ImpBrush*			m_pCurrentBrush;
    
	// Size of the brush.
	int m_nSize;
    
    // Width of the line brush
    int m_nLineWidth;
    
    // Angle of the line brush
    int m_nLineAngle;

	ImpressionistUI*	m_pUI;

// Operations
public:
	// Get the color of the original picture at the specified coord
	GLubyte* GetOriginalPixel( int x, int y );   
	// Get the color of the original picture at the specified point	
	GLubyte* GetOriginalPixel( const Point p );
    
    // Get the color of another picture at the specified coord
    GLubyte* GetAnotherPixel( int x, int y );
    // Get the color of another picture at the specified point
    GLubyte* GetAnotherPixel( const Point p );
    
    // Get the color of another picture at the specified coord
    GLubyte* GetBlackAndWhitePixel( int x, int y );
    // Get the color of another picture at the specified point
    GLubyte* GetBlackAndWhitePixel( const Point p );
    



private:
	char			m_imageName[256];
    char			m_anotherImageName[256];
    char            m_blackAndWhiteImageName[256];
    char            m_alphaMapImageName[256];

};

extern void MessageBox(char *message);

#endif
