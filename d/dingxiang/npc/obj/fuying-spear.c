//Edit By Subzero
#include <weapon.h>
#include <ansi.h>

inherit CLUB;

void create()
{
        set_name(CYN"��ӥǹ"NOR,({ "fuying qiang", "qiang", "spear" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 15000);
                set("material", "steel");
                set("rumor", 1);
                set("no_sell", 1);
                set("super", 6);
                set("weapon_prop/parry", 5);
                set("weapon_prop/dodge", -5);
                set("wield_neili", 300);
                set("wield_maxforce", 800);
                set("wield_str", 23);
                set("long", CYN"��ӥǹ�ഫΪ��˹�ɽ������Ķ̸���ǹ��������Ѫ�ۣ�ǹ���ϻ�װ�б������ɷ�ӥ��״��ǹ����
���������˵���������ǹΪͻ�ʿɺ�ͻ�����ã���ӥǹ�����ͻ���ɺ�������ǹ���������ƣ�ÿ
ÿǹ��һ�������ַ������ˡ�
\n"NOR);
                set("wield_msg", CYN"$N"+CYN+"�Ѷ̸˵�$n"+CYN+"�����ڵ������һ�£�����������ҡ������ʳ���������ĵ�������\n"NOR);
                set("unwield_msg", WHT "$N"+WHT+"�������һƬǹ����ǹ��ɢ����$n"+WHT+"�ѱ����������\n" NOR);                
        }
   init_club(380);
        setup();
}
