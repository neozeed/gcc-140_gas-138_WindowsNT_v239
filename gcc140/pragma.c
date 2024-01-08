#define DEFAULT_ALIGN 32

static int pack_align = DEFAULT_ALIGN;
static int was_pragma = 0;

pragma_pack(val)
int val;
{
pack_align = 8 * val;
was_pragma = 1;
}

pragma_align_val()
{
return pack_align;
}

pragma_pack_default()
{
pack_align = DEFAULT_ALIGN;
}

int pragma_pack_seen()
{
return was_pragma;
}
