#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
    	set_name(NOR + YEL "���ս��" NOR, ({ "feituo jinjia", "feituo", "jinjia", "armor", "jia", }) );
        set_weight(10000);
        set("unit", "��");
      	set("long", YEL "����һ���ûƽ������ɵĻ��ף����ϵ���ű�����\n"
                    "������ա���˵��ֻ�и߲������ſ�ʹ�÷��ձ�ǡ�\n" NOR);
        set("material", "cloth");
        set("value",8000);
        set("treasure", 1);
        set("armor_prop/dodge", 30);
        set("armor_prop/armor", 800);
        set("stable", 0);
        setup();
        
}
