// XiaoYao 

#include <armor.h>
#include <ansi.h>
inherit CLOTH;
inherit F_UNIQUE;
void create()
{
        set_name(HIY"�ڲ���"NOR, ({ "wucan yi", "wucan", "yi" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "��һ����ǹ����ı��£����ô�ѩɽ�ϵ��ڲϲ�˿֯�ɵġ�\n");
                set("material", "silk");
                set("unit", "��");
                set("value", 1000000);
                set("treasure", 1);
                set("wear_msg", HIY"ֻ��$N���������ӣ�ǰһ�顢��һ��Ŀ���һ���������ϡ�\n" NOR);
                set("armor_prop/armor", 180);
        }
        setup();
}

