inherit ITEM;

void create()
{
        set_name("����С��¯", ({ "xiao huolu" }) );
        set_weight(12000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "��ɫ�������Ƶ�С��¯,�ð������.\n");
                set("value", 500);
        }
}


