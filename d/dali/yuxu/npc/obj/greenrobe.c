// greenrobe.c ��ɫ����
// By Marz
// Modify By River 98/12
#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
	set_name(HIC"��ɫ����"NOR, ({"qingse daopao", "pao", "cloth", "daopao"}) );
        set_weight(1500);
        if( clonep())
             set_default_object(__FILE__);
        else { 
            set("unit", "��");
	    set("long", "���Ǽ��ʵ��������ɫ���ۣ����ϻ����Ż��ء�\n");
            set("material", "cloth");
            set("armor_prop/armor", 10);
            }
        setup();
}
