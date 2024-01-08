#line 1 "omfwrite.c"



















#line 1 "as.h"
























#line 26 "as.h"






#line 33 "as.h"

























#line 1 "/MSVC32S/C386/INCLUDE\\stdio.h"















#pragma pack(4)



typedef unsigned int size_t;

#line 23 "/MSVC32S/C386/INCLUDE\\stdio.h"


typedef char *va_list;

#line 28 "/MSVC32S/C386/INCLUDE\\stdio.h"









#line 38 "/MSVC32S/C386/INCLUDE\\stdio.h"



struct _iobuf {
	char *_ptr;
	int   _cnt;
	char *_base;
	int   _flag;
	int   _file;
	int   _charbuf;
	int   _bufsiz;
	int   __tmpnum;
	};
typedef struct _iobuf FILE;

#line 54 "/MSVC32S/C386/INCLUDE\\stdio.h"





























extern FILE _cdecl _iob[];
#line 85 "/MSVC32S/C386/INCLUDE\\stdio.h"





typedef long fpos_t;

#line 93 "/MSVC32S/C386/INCLUDE\\stdio.h"
























int _cdecl _filbuf(FILE *);
int _cdecl _flsbuf(int, FILE *);
FILE * _cdecl _fsopen( char *,  char *, int);
void _cdecl clearerr(FILE *);
int _cdecl fclose(FILE *);
int _cdecl fcloseall(void);
FILE * _cdecl fdopen(int,  char *);
int _cdecl feof(FILE *);
int _cdecl ferror(FILE *);
int _cdecl fflush(FILE *);
int _cdecl fgetc(FILE *);
int _cdecl fgetchar(void);
int _cdecl fgetpos(FILE *, fpos_t *);
char * _cdecl fgets(char *, int, FILE *);
int _cdecl fileno(FILE *);
int _cdecl flushall(void);
FILE * _cdecl fopen( char *,  char *);
int _cdecl fprintf(FILE *,  char *, ...);
int _cdecl fputc(int, FILE *);
int _cdecl fputchar(int);
int _cdecl fputs( char *, FILE *);
size_t _cdecl fread(void *, size_t, size_t, FILE *);
FILE * _cdecl freopen( char *,  char *, FILE *);
int _cdecl fscanf(FILE *,  char *, ...);
int _cdecl fsetpos(FILE *,  fpos_t *);
int _cdecl fseek(FILE *, long, int);
long _cdecl ftell(FILE *);
size_t _cdecl fwrite( void *, size_t, size_t, FILE *);
int _cdecl getc(FILE *);
int _cdecl getchar(void);
char * _cdecl gets(char *);
int _cdecl getw(FILE *);
void _cdecl perror( char *);
int _cdecl _pclose(FILE *);
FILE * _cdecl _popen( char *,  char *);
int _cdecl printf( char *, ...);
int _cdecl putc(int, FILE *);
int _cdecl putchar(int);
int _cdecl puts( char *);
int _cdecl putw(int, FILE *);
int _cdecl remove( char *);
int _cdecl rename( char *,  char *);
void _cdecl rewind(FILE *);
int _cdecl rmtmp(void);
int _cdecl scanf( char *, ...);
void _cdecl setbuf(FILE *, char *);
int _cdecl setvbuf(FILE *, char *, int, size_t);
int _cdecl sprintf(char *,  char *, ...);
int _cdecl sscanf( char *,  char *, ...);
char * _cdecl tempnam(char *, char *);
FILE * _cdecl tmpfile(void);
char * _cdecl tmpnam(char *);
int _cdecl ungetc(int, FILE *);
int _cdecl unlink( char *);
int _cdecl vfprintf(FILE *,  char *, va_list);
int _cdecl vprintf( char *, va_list);
int _cdecl vsprintf(char *,  char *, va_list);

#line 176 "/MSVC32S/C386/INCLUDE\\stdio.h"
























#pragma pack()
#line 59 "as.h"
#line 1 "/MSVC32S/C386/INCLUDE\\assert.h"
























#line 26 "/MSVC32S/C386/INCLUDE\\assert.h"
#line 60 "as.h"
























#line 85 "as.h"
#line 86 "as.h"
				







#line 95 "as.h"


char	*xmalloc();		
char	*xrealloc();		










				
int	seen_at_least_1_file();
void	bump_line_counters();
void	new_logical_line();
void	as_where();
void	as_perror();
void	as_howmuch();
				
void	input_scrub_begin();
void	input_scrub_end();
char	*input_scrub_new_file();
char	*input_scrub_next_buffer();































typedef enum
{
	SEG_ABSOLUTE,
	SEG_TEXT,
	SEG_DATA,
	SEG_BSS,
	SEG_UNKNOWN,
	SEG_NONE,		
	SEG_PASS1,		
	SEG_GOOF,		
				
				
	SEG_BIG,			
	SEG_DIFFERENCE		
}		segT;


typedef unsigned char	subsegT;

extern subsegT			now_subseg;
				


extern segT			now_seg;
				
				


extern char * seg_name[];
extern  int   seg_N_TYPE[];
extern  segT  N_TYPE_seg[];
void	subsegs_begin();
void	subseg_change();
void	subseg_new();



typedef enum
{
	rs_fill,		
				
				
				

	rs_align,		
				
	rs_org,			
				

	rs_machine_dependent,



}
relax_stateT;




typedef unsigned long int relax_substateT;

typedef unsigned long int relax_addressT;
				





















struct frag			
{
	long unsigned int fr_address; 
	struct frag *fr_next;	
				

	long int fr_fix;	
				
	long int fr_var;	
				
	struct symbol *fr_symbol; 
	long int fr_offset;	
	char	*fr_opcode;	
	relax_stateT fr_type;   
	relax_substateT	fr_subtype;
		
	char	fr_pcrel_adjust;
	char	fr_bsr;
	char	fr_literal [1];	
				
};


				

typedef struct frag fragS;

extern fragS *	frag_now;	
				
				
				


extern fragS zero_address_frag;	
extern fragS  bss_address_frag;	

void		frag_new();
char *		frag_more();
char *		frag_var();
void		frag_wane();
void		frag_align();




extern char
flagseen[128];			

extern char *
out_file_name;			

extern int	need_pass_2;	

extern char *module_name;	

#line 292 "as.h"


#line 21 "omfwrite.c"
#line 1 "md.h"

























typedef struct {
  char *	poc_name;	
  void		(*poc_handler)();	
  int		poc_val;	
}
pseudo_typeS;
extern  pseudo_typeS md_pseudo_table[];




typedef struct
{
	long	rlx_forward;	
	long	rlx_backward;	
	unsigned char rlx_length;	
	relax_substateT rlx_more;	
				
}
relax_typeS;

extern  relax_typeS md_relax_table[]; 

char *		md_atof();
void		md_assemble();
void		md_begin();
void		md_convert_frag();
void		md_end();
int		md_estimate_size_before_relax();
void		md_number_to_chars();


#line 22 "omfwrite.c"
#line 1 "subsegs.h"






































struct frchain			
{				
  struct frag *	frch_root;	
  struct frag *	frch_last;	
  struct frchain * frch_next;	
  segT		frch_seg;	
  subsegT	frch_subseg;	
};

typedef struct frchain frchainS;

extern frchainS * frchain_root;	
				

extern frchainS * frchain_now;
				
				
				
				

extern frchainS * data0_frchainP;
				
				
				
				


#line 23 "omfwrite.c"
#line 1 "obstack.h"





















































































































#line 119 "obstack.h"



#line 123 "obstack.h"

struct _obstack_chunk		
{
  char  *limit;			
  struct _obstack_chunk *prev;	
  char	contents[4];		
};

struct obstack		
{
  long	chunk_size;		
  struct _obstack_chunk* chunk;	
  char	*object_base;		
  char	*next_free;		
  char	*chunk_limit;		
  int	temp;			
  int   alignment_mask;		
  struct _obstack_chunk *(*chunkfun) (); 
  void (*freefun) ();		
};
















































































































































































#line 320 "obstack.h"




extern struct obstack *_obstack;
















































































#line 406 "obstack.h"

#line 408 "obstack.h"

#line 410 "obstack.h"

#line 24 "omfwrite.c"
#line 1 "struc-sy.h"




















#line 1 "aoutgnu.h"







struct exec
{
  unsigned long a_info;		
  unsigned a_text;		
  unsigned a_data;		
  unsigned a_bss;		
  unsigned a_syms;		
  unsigned a_entry;		
  unsigned a_trsize;		
  unsigned a_drsize;		
};

#line 21 "aoutgnu.h"


enum machine_type {


#line 27 "aoutgnu.h"
  M_OLDSUN2 = 0,
#line 29 "aoutgnu.h"


#line 32 "aoutgnu.h"
  M_68010 = 1,
#line 34 "aoutgnu.h"


#line 37 "aoutgnu.h"
  M_68020 = 2,
#line 39 "aoutgnu.h"


#line 42 "aoutgnu.h"
  M_SPARC = 3,
#line 44 "aoutgnu.h"
  
  M_386 = 100,
};



#line 51 "aoutgnu.h"




























#line 80 "aoutgnu.h"










#line 91 "aoutgnu.h"



#line 95 "aoutgnu.h"



#line 99 "aoutgnu.h"



#line 103 "aoutgnu.h"



#line 107 "aoutgnu.h"



#line 111 "aoutgnu.h"




#line 116 "aoutgnu.h"






#line 123 "aoutgnu.h"









#line 133 "aoutgnu.h"









#line 143 "aoutgnu.h"




#line 148 "aoutgnu.h"


struct nlist {
  union {
    char *n_name;
    struct nlist *n_next;
    long n_strx;
  } n_un;
  unsigned char n_type;
  char n_other;
  short n_desc;
  unsigned long n_value;
};
#line 162 "aoutgnu.h"



#line 166 "aoutgnu.h"


#line 169 "aoutgnu.h"


#line 172 "aoutgnu.h"


#line 175 "aoutgnu.h"


#line 178 "aoutgnu.h"


#line 181 "aoutgnu.h"



#line 185 "aoutgnu.h"


#line 188 "aoutgnu.h"


#line 191 "aoutgnu.h"





































struct relocation_info
{
  
  int r_address;
  
  unsigned int r_symbolnum:24;
  


  unsigned int r_pcrel:1;
  

  unsigned int r_length:2;
  





  unsigned int r_extern:1;
  






  unsigned int r_pad:4;
#line 257 "aoutgnu.h"
};
#line 259 "aoutgnu.h"


#line 262 "aoutgnu.h"
#line 22 "struc-sy.h"


#line 25 "struc-sy.h"

struct symbol			
{
  struct nlist	sy_nlist;	
  long unsigned sy_name_offset;	
				
				
				
  long int	sy_number;	
				
				
  struct symbol * sy_next;	
  struct frag *	sy_frag;	
  struct symbol *sy_forward;	
};

typedef struct symbol symbolS;


				
				




				
				

typedef unsigned valueT;	



















#line 25 "omfwrite.c"
#line 1 "write.h"
































struct bit_fix {
  int			fx_bit_size;	
  int			fx_bit_offset;	
  long			fx_bit_base;	

  long                  fx_bit_base_adj;
  long			fx_bit_max;	
  long			fx_bit_min;	
  long			fx_bit_add;	
};
typedef struct bit_fix bit_fixS;




struct fix
{
  fragS *		fx_frag;	
  long int		fx_where;	
  symbolS *		fx_addsy; 
  symbolS *		fx_subsy; 
  long int		fx_offset;	
  struct fix *		fx_next;	
  short int		fx_size;	
  char			fx_pcrel;	
  char			fx_pcrel_adjust;
  char			fx_im_disp;	
  bit_fixS *		fx_bit_fixP;	  
  char			fx_bsr;		



#line 66 "write.h"
};

typedef struct fix	fixS;


extern fixS *	text_fix_root;	
extern fixS *	data_fix_root;	
extern fixS **	seg_fix_rootP;	

bit_fixS *bit_fix_new();


#line 26 "omfwrite.c"
#line 1 "symbols.h"



















extern struct obstack	notes; 



extern unsigned int local_bss_counter; 
				


extern symbolS * symbol_rootP;	
extern symbolS * symbol_lastP;	

extern symbolS	abs_symbol;

symbolS *	symbol_find();
void		symbol_begin();
char *		local_label_name();
void		local_colon();
symbolS *	symbol_new();
void		colon();
void		symbol_table_insert();
symbolS *	symbol_find_or_make();


#line 27 "omfwrite.c"

#line 1 "xenixomf.h"












































































































































#line 29 "omfwrite.c"
#line 1 "msomf.h"
























#line 30 "omfwrite.c"



#line 34 "omfwrite.c"

#line 36 "omfwrite.c"

void	append();






static unsigned char nbytes_r_length [] = {
  15, 0, 1, 15, 9
  };


static struct frag *	text_frag_root;
static struct frag *	data_frag_root;

static struct frag *	text_last_frag;	
static struct frag *	data_last_frag;	

static struct exec	the_exec;

static long int string_byte_count;
static long int stab_symbol_count;

void	relax_segment();
long int	fixup_segment();

static void threads(type, trgt_thrd, frm_thrd)
int type;
int *trgt_thrd, *frm_thrd;
{
	  switch (type)
	  {
	    case (6):	*trgt_thrd = 1;
				*frm_thrd = 1;
				break;
	    case (8):	*trgt_thrd = 3;
				*frm_thrd = 1;
				break;
	    case (4):	*trgt_thrd = 2;
				*frm_thrd = 0;
				break;
	    case (6|1):	*trgt_thrd = 1;
				*frm_thrd = 1;
				break;
	    case (4|1):	*trgt_thrd = 2;
				*frm_thrd = 0;
				break;
	    default:		*trgt_thrd = 0;
				*frm_thrd = 1;
				break;
	  }
}

void
write_object_file()
{
  register struct frchain *	frchainP; 
  register fragS *		fragP;	
  register struct frchain *	next_frchainP;
  register fragS * *		prev_fragPP;
  register char *		name;
  register symbolS *		symbolP;
  register symbolS **		symbolPP;
  
  unsigned long
  	text_siz,
	data_siz,
	syms_siz,
	tr_siz,
	dr_siz;
  void output_file_create();
  void output_file_append();
  void output_file_close();
  extern long omagic;		


  






  for ( frchainP=frchain_root; frchainP; frchainP=frchainP->frch_next )
    {
      subseg_new (frchainP -> frch_seg, frchainP -> frch_subseg);
      frag_align ((2), 0);
				
				
      



      frag_wane (frag_now);
      frag_now -> fr_fix	= 0;
      ;
      
      
    }

  




  prev_fragPP = &text_frag_root;
  for ( frchainP=frchain_root; frchainP; frchainP=next_frchainP )
    {
      ;
      * prev_fragPP = frchainP -> frch_root;
      prev_fragPP = & frchainP -> frch_last -> fr_next;
      if (   ((next_frchainP = frchainP->frch_next) == 0)
	  || next_frchainP == data0_frchainP)
	{
	  prev_fragPP = & data_frag_root;
	  if ( next_frchainP )
	    {
	      text_last_frag = frchainP -> frch_last;
	    }
	  else
	    {
	      data_last_frag = frchainP -> frch_last;
	    }
	}
    }				

  relax_segment (text_frag_root, SEG_TEXT);
  relax_segment (data_frag_root, SEG_DATA);
  



  text_siz=text_last_frag->fr_address;

  



  if (data_frag_root)
      data_siz=data_last_frag->fr_address;
  else
      data_siz = 0;

  bss_address_frag . fr_address = 0;
	      
  



















  string_byte_count = sizeof( string_byte_count );

  
  for(symbolP=symbol_rootP;symbolP;symbolP=symbolP->sy_next) {
  	if(symbolP->sy_forward) {
		symbolP->sy_nlist. n_value+=symbolP->sy_forward->sy_nlist. n_value+symbolP->sy_forward->sy_frag->fr_address;
		symbolP->sy_forward=0;
	}
  }
  symbolPP = & symbol_rootP;	
  {
    register long int		symbol_number;

    symbol_number = 1;  stab_symbol_count = 0;

    while (symbolP  = * symbolPP)
      {
	name = symbolP -> sy_nlist .n_un. n_name;
	symbolP -> sy_nlist. n_value += symbolP -> sy_frag -> fr_address;
	if ( !name || (symbolP->sy_nlist.n_type&0340)
	    || (name[0]!='\001' && (flagseen ['L'] || name [0] != 'L' )))
	  {
	    if (((symbolP->sy_nlist.n_type)==(0) || ((symbolP->sy_nlist.n_type) == (0|1))))
	    	symbolP -> sy_number = symbol_number ++;
	    else
	    	symbolP -> sy_number = 0;
	    if (symbolP->sy_nlist.n_type&0340)
		stab_symbol_count++;
	    if (name && symbolP->sy_nlist.n_type&0340)
	      {			
		symbolP -> sy_name_offset = string_byte_count;
		string_byte_count += strlen (symbolP  -> sy_nlist .n_un. n_name) + 1;
	      }
	    else			
		symbolP -> sy_name_offset = 0;
	    symbolPP = & (symbolP -> sy_next);
	  }
	else
	    * symbolPP = symbolP -> sy_next;
      }				

    syms_siz = sizeof( struct nlist) * symbol_number;
  }

  





  subseg_change( SEG_TEXT, 0);

  for (fragP = text_frag_root;  fragP;  fragP = fragP -> fr_next)
    {
      switch (fragP -> fr_type)
	{
	case rs_align:
	case rs_org:
	  fragP -> fr_type = rs_fill;
	  ;
	  ;
	  fragP -> fr_offset
	    =     fragP -> fr_next -> fr_address
	      -   fragP -> fr_address
		- fragP -> fr_fix;
	  break;

	case rs_fill:
	  break;

	case rs_machine_dependent:
	  md_convert_frag (fragP);
	  




	  frag_wane (fragP);
	  break;

	default:
	  { as_fatal ("Case value %d unexpected at line %d of file \"%s\"\n", fragP -> fr_type, 283, "omfwrite.c"); };
	  break;
	}			
    }				


  subseg_change( SEG_DATA, 0);

  for (fragP = data_frag_root;  fragP;  fragP = fragP -> fr_next)
    {
      switch (fragP -> fr_type)
	{
	case rs_align:
	case rs_org:
	  fragP -> fr_type = rs_fill;
	  ;
	  ;
	  fragP -> fr_offset
	    =     fragP -> fr_next -> fr_address
	      -   fragP -> fr_address
		- fragP -> fr_fix;
	  break;

	case rs_fill:
	  break;

	case rs_machine_dependent:
	  md_convert_frag (fragP);
	  




	  frag_wane (fragP);
	  break;

	default:
	  { as_fatal ("Case value %d unexpected at line %d of file \"%s\"\n", fragP -> fr_type, 320, "omfwrite.c"); };
	  break;
	}			
    }				

  subseg_change( SEG_TEXT, 0);

  fixup_segment (text_fix_root, 4);
  fixup_segment (data_fix_root, 6);
  output_file_create (out_file_name);
  omf_initialize_a_out(module_name, text_siz, data_siz,
		       (long) local_bss_counter, 0L,
		       flagseen['g'], stab_symbol_count * sizeof(struct nlist),
		       string_byte_count);





  for (   symbolP = symbol_rootP;   symbolP;   symbolP = symbolP -> sy_next   )
  {
      if (((symbolP->sy_nlist. n_type)==(0) || ((symbolP->sy_nlist. n_type) == (0|1))))
      {
          if (((symbolP->sy_nlist. n_type) == (0|1)))
          {
              omf_start_comdef();
              omf_comdef(symbolP->sy_nlist .n_un. n_name, 0x62, symbolP->sy_nlist. n_value, 0L);
              omf_end_comdef();
          }
          else
              omf_extdef(symbolP->sy_nlist .n_un. n_name, 0);
      }
  }




  for (   symbolP = symbol_rootP;   symbolP;   symbolP = symbolP -> sy_next   )
  {
    if (((symbolP->sy_nlist. n_type)==(6|1) || (symbolP->sy_nlist. n_type)==(4|1) || (symbolP->sy_nlist. n_type)==(2|1)))
    {
        unsigned int group = 0, segment = 0;

        if (symbolP->sy_nlist. n_type == (4|1))
            segment = 1;
        if (symbolP->sy_nlist. n_type == (6|1))
        {
            group = 1;  segment = 2;
        }
        
        omf_start_pubdef(1, group, segment, 0);
        omf_pubdef(1, symbolP->sy_nlist .n_un. n_name, symbolP->sy_nlist. n_value, 0);
        omf_end_pubdef();
    }
  }
  

  

  omf_start_thread(1);
  omf_thread(0, 0, 0, 3);
  omf_thread(1, 0, 0, 2);
  omf_thread(2, 0, 0, 1);
  omf_thread(3, 0, 0, 4);
  omf_thread(0, 1, 0, 1);
  omf_thread(1, 1, 1, 1);
  omf_end_thread();
  
  



  for (fragP = data_frag_root;  fragP;  fragP = fragP -> fr_next)
  {
      register long int count;
      register char * fill_literal;
      register long int fill_size;
      register fixS * fixP;
      register symbolS * symbolP;
      int started_fixup;

      ;

      if (fragP->fr_fix != 0 || fragP->fr_offset != 0)
      {
          omf_start_ledata(1, 2, fragP->fr_address);
          if (fragP->fr_fix != 0)
              omf_ledata(fragP->fr_literal, (int)fragP->fr_fix);
          fill_literal = fragP->fr_literal + fragP -> fr_fix;
          fill_size = fragP->fr_var;
          count = fragP -> fr_offset;
	  if ((fragP->fr_fix + count * fill_size) < 1016)
	  {
              for ( ; count; count--)
                  omf_ledata(fill_literal, (int)fill_size);
	  }
	  else  
	  {
	      



	      register int fcount;

	      fcount = (1016 - fragP->fr_fix) / fill_size;
	      count -= fcount;
	      for ( ; fcount > 0; fcount--)
                  omf_ledata(fill_literal, (int)fill_size);
	      
	  }
          omf_end_ledata();

          


          fixP = data_fix_root;  started_fixup = 0;
          for ( ;  fixP;  fixP = fixP -> fx_next)
          {
              if (fixP->fx_frag == fragP && (symbolP = fixP->fx_addsy))
              {
		  int trgt_thrd, frm_thrd;
		  int external = ((symbolP->sy_nlist. n_type)==(0) || ((symbolP->sy_nlist. n_type) == (0|1)));

		  threads(symbolP->sy_nlist. n_type, &trgt_thrd, &frm_thrd);
		  if (fixP->fx_pcrel)
			frm_thrd = 0;

                  if (!started_fixup)
                  {
                      omf_start_fixup(1);
                      started_fixup++;
                  }
                  omf_fixup(1, !fixP->fx_pcrel,
		        nbytes_r_length [fixP->fx_size], fixP->fx_where,
    			external ? 0 : 1,
    			external ? 5 : frm_thrd,
    			external ? 0 : 1,
    			external ? 2 : trgt_thrd,
    			1, 
			0, 
    			((symbolP->sy_nlist. n_type)==(0) || ((symbolP->sy_nlist. n_type) == (0|1))) ? symbolP->sy_number : 0,
			0);
	      }
          }
    	  if (started_fixup)
              omf_end_fixup();
	  
	  while (count > 0)	
	  {
	      unsigned long address;
	      unsigned int len;

              address = fragP->fr_address + fragP->fr_fix +
			  (fragP->fr_offset - count) * fill_size;
              omf_start_ledata(1, 2, address);
              for ( len = 0; count && (len < 1000); count--, len += fill_size)
                  omf_ledata(fill_literal, (int)fill_size);
              omf_end_ledata();
	  }
      }
  }

  for (fragP = text_frag_root;  fragP;  fragP = fragP -> fr_next)
  {
      register long int count;
      register char * fill_literal;
      register long int fill_size;
      register fixS * fixP;
      register symbolS * symbolP;
      int started_fixup;

      ;

      if (fragP->fr_fix != 0 || fragP->fr_offset != 0)
      {
          omf_start_ledata(1, 1, fragP->fr_address);
          if (fragP->fr_fix != 0)
              omf_ledata(fragP->fr_literal, (int)fragP->fr_fix);
          fill_literal = fragP->fr_literal + fragP -> fr_fix;
          fill_size = fragP->fr_var;
          for (count = fragP -> fr_offset;  count;  count --)
              omf_ledata(fill_literal, (int)fill_size);
          omf_end_ledata();

          


          fixP = text_fix_root;  started_fixup = 0;
          for ( ;  fixP;  fixP = fixP -> fx_next)
          {
              if (fixP->fx_frag == fragP && (symbolP = fixP->fx_addsy))
              {
		  int trgt_thrd, frm_thrd;
		  int external = ((symbolP->sy_nlist. n_type)==(0) || ((symbolP->sy_nlist. n_type) == (0|1)));

		  threads(symbolP->sy_nlist. n_type, &trgt_thrd, &frm_thrd);
		  if (fixP->fx_pcrel)
			frm_thrd = 0;

                  if (!started_fixup)
                  {
                      omf_start_fixup(1);
                      started_fixup++;
                  }
                  omf_fixup(1, !fixP->fx_pcrel,
		        nbytes_r_length [fixP->fx_size], fixP->fx_where,
    			external ? 0 : 1,
    			external ? 5 : frm_thrd,
    			external ? 0 : 1,
    			external ? 2 : trgt_thrd,
    			1, 
			0, 
    			external ? symbolP->sy_number : 0,
			0);
	      }
          }
    	  if (started_fixup)
              omf_end_fixup();
      }
  }






  if (flagseen['g'] && stab_symbol_count)
  {   
      long count = 0, ncount = 0;
      symbolS *last_startP;
      char *temp;
      symbolS *fsymP;
      int i;
      int start_fixup = 0;

      omf_start_ledata(1, 5, 0);
      last_startP = symbol_rootP;
      for (symbolP = symbol_rootP; symbolP; symbolP = symbolP -> sy_next)
      {
	 if (symbolP->sy_nlist.n_type & 0340)
	 {
            if ((ncount + 1) * sizeof(struct nlist) >= 1016)
            {
               omf_end_ledata();

               

               start_fixup = 0;
	       for (i = 0, fsymP=last_startP; i < ncount; fsymP=fsymP->sy_next)
	       {
	          if (fsymP->sy_nlist.n_type & 0340)
		  {
                     if (fsymP->sy_nlist. n_type & 036) 
		     {
		       int trgt_thrd, frm_thrd;
		       int external = ((fsymP->sy_nlist. n_type & 036)==(0) || ((fsymP->sy_nlist. n_type & 036) == (0|1)));

		       threads(fsymP->sy_nlist. n_type & 036,&trgt_thrd,&frm_thrd);
		       if (!start_fixup)
		       {
                           omf_start_fixup(1);
			   start_fixup++;
		       }
			
		       omf_fixup(1, 1, 
		          9, i * sizeof(struct nlist) + ((size_t) &((struct nlist *)0)->n_value), 
    			  external ? 0 : 1,
    			  external ? 5 : frm_thrd,
    			  external ? 0 : 1,
    			  external ? 2 : trgt_thrd,
    			  1, 
			  0, 
    			  external ? fsymP->sy_number : 0,
			  0);
		     }
		     i++;
		  }
	       }
	       if (start_fixup)
                  omf_end_fixup();

               

               ncount = 0;  last_startP = symbolP;
               omf_start_ledata(1, 5, count*sizeof(struct nlist));
            }
            temp = symbolP->sy_nlist.n_un.n_name;
            symbolP->sy_nlist.n_un.n_strx = symbolP->sy_name_offset;
            omf_ledata(&(symbolP->sy_nlist), sizeof(struct nlist));
            symbolP->sy_nlist.n_un.n_name = temp;
   	    ncount++;  count++;
	 }
      }
      omf_end_ledata();
      start_fixup = 0;
      for (i = 0, fsymP = last_startP; i < ncount; fsymP = fsymP->sy_next)
      {
         if (fsymP->sy_nlist.n_type & 0340)
	 {
            if (fsymP->sy_nlist. n_type & 036) 
	    {
	      int trgt_thrd, frm_thrd;
	      int external = ((fsymP->sy_nlist. n_type & 036)==(0) || ((fsymP->sy_nlist. n_type & 036) == (0|1)));

	      threads(fsymP->sy_nlist. n_type & 036,&trgt_thrd,&frm_thrd);
	      if (!start_fixup)
              {
                 omf_start_fixup(1);
                 start_fixup++;
              }
	      omf_fixup(1, 1, 
	         9, i * sizeof(struct nlist) + ((size_t) &((struct nlist *)0)->n_value),
   		  external ? 0 : 1,
   		  external ? 5 : frm_thrd,
   		  external ? 0 : 1,
   		  external ? 2 : trgt_thrd,
   		  1, 
                  0, 
   		  external ? fsymP->sy_number : 0,
		  0);
	    }
	    i++;
	 }
      }
      if (start_fixup)
         omf_end_fixup();

      count = sizeof(string_byte_count);  ncount = count;
      omf_start_ledata(1, 6, 0);
      omf_ledata(&string_byte_count, sizeof(string_byte_count));
      for (symbolP = symbol_rootP; symbolP; symbolP = symbolP -> sy_next)
      {
         if (symbolP->sy_nlist.n_type & 0340 && symbolP -> sy_nlist .n_un. n_name)
	 {
	    int len = strlen(symbolP -> sy_nlist .n_un. n_name) + 1;

	    if (ncount + len > 1016)
	    {
	       omf_end_ledata();
               omf_start_ledata(1, 6, count);
	       ncount = 0;
	    }
            omf_ledata(symbolP->sy_nlist .n_un. n_name, len);
	    count += len;  ncount += len;
	 }
      }
      omf_end_ledata();
  }
  

  omf_modend(1);
  output_file_close (out_file_name);

}				
