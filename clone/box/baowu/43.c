#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(NOR + CYN "��⬼�" NOR, ({ "ruanwei jia", "ruanwei", "jia" }));
        set_weight(8000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", NOR + CYN "
����һ�����������ף��ֿ��º������ۡ�������һ�������
��⬼ף�ֻ�����������ں�������������ȴ���Ǽ�Ӳʤ����
������Χ�������˵��̣������ޱȡ�\n" NOR);
                set("value",8000);
                set("treasure", 1);
                set("material", "cloth");
                set("armor_prop/armor", 550);
                set("stable", 100);
        }
        setup();
}


