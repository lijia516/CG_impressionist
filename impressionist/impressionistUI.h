//
// impressionistUI.h
//
// The header file for the UI part
//

#ifndef ImpressionistUI_h
#define ImpressionistUI_h

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_File_Chooser.H>		// FLTK file chooser
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Value_Slider.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Light_Button.H>
#include <FL/Fl_Color_Chooser.H>
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Float_Input.H>


#include "impressionist.h"
#include "originalView.h"
#include "paintView.h"

#include "impBrush.h"

const int FLT_WIDTH = 5;
const int FLT_HEIGHT = 5;

// Each filter type has an associated constant.
enum
{
    BOX_FILTER = 0,
    BARTLETT_FILTER = 1,
    GAUSSIAN_FILTER = 2,
    NUM_FILTER_TYPE// Make sure this stays at the end!
};

class ImpressionistUI {
public:
	ImpressionistUI();
	~ImpressionistUI();

	// The FLTK widgets
	Fl_Window*			m_mainWindow;
	Fl_Menu_Bar*		m_menubar;
								
	PaintView*			m_paintView;
	OriginalView*		m_origView;

// for brush dialog
	Fl_Window*			m_brushDialog;
	Fl_Choice*			m_BrushTypeChoice;
    Fl_Choice*			m_LineAngleTypeChoice;

    Fl_Slider*			m_BrushSizeSlider;
    Fl_Slider*			m_BrushAlphaSlider;
	Fl_Slider*			m_BrushLineWidthSlider;
    Fl_Slider*			m_BrushLineAngleSlider;
    Fl_Slider*			m_DrawSpaceSlider;
    
    Fl_Light_Button*    m_EdgeClippingLightButton;
    Fl_Light_Button*    m_AnotherEdgeClippingLightButton;
    Fl_Light_Button*    m_MultiColorLightButton;
    Fl_Light_Button*    m_RandSpaceLightButton;
    Fl_Light_Button*    m_AnotherGradientLightButton;
    Fl_Light_Button*    m_colorBlendingLightButton;
    
    Fl_Color_Chooser*   m_ColorChooser;
    
// for apply filter dialog
    Fl_Window*			m_applyFilterDialog;
    Fl_Button*          m_PreviewFilterButton;
    Fl_Button*          m_ApplyFilterButton;
    Fl_Button*          m_CancleFilterButton;
    Fl_Button*          m_RestoreImageButton;
    Fl_Int_Input*       m_KernelWidthInput;
    Fl_Int_Input*       m_KernelHeightInput;
    Fl_Float_Input*     m_KernelValues[FLT_WIDTH * FLT_HEIGHT];
    Fl_Choice*			m_FilterTypeChoice;
    
    Fl_Float_Input*     m_KernelScaleInput;
    Fl_Float_Input*     m_KernelOffsetInput;
    
	Fl_Button*          m_ClearCanvasButton;
    Fl_Button*          m_AutoPaintButton;
    Fl_Button*          m_CoarseToFinePaintButton;

	// Member functions
	void				setDocument(ImpressionistDoc* doc);
	ImpressionistDoc*	getDocument();

	void				show();
	void				resize_windows(int w, int h);

	// Interface to get attribute

	int					getSize();
	void				setSize(int size);
    
    int					getDrawSpace();
    void				setDrawSpace(int drawSpace);
    
    float				getAlpha();
    void				setAlpha(float alpha);
    
    int					getLineWidth();
    void				setLineWidth(int lineWidth);
    
    int					getLineAngle();
    void				setLineAngle(int lineAngle);
    
    
    double              getKernelScale();
    double              getKernelOffset();
    int                 getKernelHeight();
    int                 getKernelWidth();
    double*             getKernelValues();
    
    bool                getMultiColor();
    bool                getEdgeClipping();
    bool                getAnotherEdgeClipping();
    bool                getRandSpace();
    bool                getAnotherGradient();
    
    bool                getColorBlending();

	// Callbacks for the image filter dialogue (different from
	// the other callbacks because they aren't static)
	void				initFltDesignUI(void);
	void				updateFilter(void);

	void				cancelFilter(void);
	void				applyFilter(void);
	void				previewFilter(void);
    
    


private:
	ImpressionistDoc*	m_pDoc;		// pointer to document to communicate with the document

	// All attributes here
	int		m_nSize;
    int		m_nDrawSpace;
    float	m_nAlpha;
    int		m_nLineWidth;
    int		m_nLineAngle;
    int     m_nLineAngleType;
    bool    m_nEdgeClipping;
    bool    m_nAnotherEdgeClipping;
    bool    m_nMultiColor;
    bool    m_nRandSpace;
    bool    m_nAnotherGradient;
    bool    m_nColorBlending;

	// These attributes are set by the filter kernel UI
	double fltKernel[FLT_WIDTH*FLT_HEIGHT];		//the kernel of the image filter
	double scale,offset;						//the divisor and offset parameter, 
												//applied after convolving to transform 
												//the filtered image into the range [0,255]
    int m_nKernelWidth;
    int m_nKernelHeight;

	// Static class members
	static Fl_Menu_Item		menuitems[];
	static Fl_Menu_Item		brushTypeMenu[NUM_BRUSH_TYPE+1];
    static Fl_Menu_Item		lineAngleTypeMenu[NUM_LINE_ANGLE_TYPE+1];
    static Fl_Menu_Item		filterTypeMenu[NUM_LINE_ANGLE_TYPE+1];

	static ImpressionistUI*	whoami(Fl_Menu_* o);

	// All callbacks here.  Callbacks are declared 
	// static
	static void	cb_load_image(Fl_Menu_* o, void* v);
    static void	cb_load_another_image(Fl_Menu_* o, void* v);
    static void	cb_load_black_and_white_image(Fl_Menu_* o, void* v);
    static void	cb_load_alpha_map_image(Fl_Menu_* o, void* v);
	static void	cb_save_image(Fl_Menu_* o, void* v);
	static void	cb_brushes(Fl_Menu_* o, void* v);
   
	static void	cb_filter_kernel(Fl_Menu_* o, void* v);
	static void	cb_clear_canvas(Fl_Menu_* o, void* v);
	static void	cb_exit(Fl_Menu_* o, void* v);
	static void	cb_about(Fl_Menu_* o, void* v);
	static void	cb_brushChoice(Fl_Widget* o, void* v);
    static void	cb_lineAngleChoice(Fl_Widget* o, void* v);
	static void	cb_clear_canvas_button(Fl_Widget* o, void* v);
    static void cb_auto_paint_button(Fl_Widget* o, void* v);
    static void cb_coarse_to_fine_paint_button(Fl_Widget* o, void* v);
    
	static void	cb_sizeSlides(Fl_Widget* o, void* v);
    static void	cb_drawSpaceSlides(Fl_Widget* o, void* v);
    static void	cb_alphaSlides(Fl_Widget* o, void* v);
    static void	cb_lineWidthSlides(Fl_Widget* o, void* v);
    static void	cb_lineAngleSlides(Fl_Widget* o, void* v);
    
    // filter
    static void	cb_applyFilter(Fl_Menu_* o, void* v);
    static void	static_cb_preview_filter_button(Fl_Widget* o, void* v);
     static void	cb_preview_filter_button(Fl_Widget* o, void* v);
    
    static void cb_filterChoice(Fl_Widget* o, void* v);
    
    static void	static_cb_apply_filter_button(Fl_Widget* o, void* v);
    void	cb_apply_filter_button(Fl_Widget* o, void* v);
    
    static void	static_cb_cancle_filter_button(Fl_Widget* o, void* v);
    void cb_cancle_filter_button(Fl_Widget* o, void* v);
    
    static void	cb_restore_image_button(Fl_Widget* o, void* v);
    
    static void cb_KernelWidthInput(Fl_Widget* o, void* v);
    static void cb_KernelHeightInput(Fl_Widget* o, void* v);
    static void cb_KernelScaleInput(Fl_Widget* o, void* v);
    static void cb_KernelOffsetInput(Fl_Widget* o, void* v);
    static void cb_view_edge_image(Fl_Menu_* o, void* v);
    static void cb_view_grayscale_image(Fl_Menu_* o, void* v);
    static void cb_view_original_image(Fl_Menu_* o, void* v);
    static void cb_view_another_image(Fl_Menu_* o, void* v);
    static void cb_edgeClippingLightButton(Fl_Widget* o, void* v);
    static void cb_anotherEdgeClippingLightButton(Fl_Widget* o, void* v);
    static void cb_multiColorLightButton(Fl_Widget* o, void* v);
    static void cb_randSpaceLightButton(Fl_Widget* o, void* v);
    static void cb_anotherGradientLightButton(Fl_Widget* o, void* v);
    static void cb_colorBlendingLightButton(Fl_Widget* o, void* v);

};

#endif

