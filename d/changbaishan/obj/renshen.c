
inherit COMBINED_ITEM;

void create()
{
        set_name("�˲�", ({ "ren shen","shen" }) );
       if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("base_unit","��");
				set("long","����һ�ó���ɽ�˲�,����������ҩ��\n");
                set("value", 3000);

                
        }

      set_amount(1);
}
