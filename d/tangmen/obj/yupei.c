// yupei.c
inherit ITEM;

void create()
{
        set_name("����", ({"yu pei", "yu","pei"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
"����һ�龫�������������������ޱȡ�\n");
	set("value", 80000);
                set("material", "stone");
        }
}

