// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// jinjia.c ���
#include <armor.h>

inherit ARMOR;

void create()
{
        set_name("�����Ӽ�", ({"golden armor","jinjia", "jia", "armor"}));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
     set("long", "һ������֯�͵ı��ף�\n");
                set("material", "steel");
                set("value", 2600);
                set("armor_prop/armor", 35);
     set("armor_prop/dodge", -5);
        }
        setup();
}


