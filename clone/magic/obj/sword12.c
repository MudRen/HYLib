// ����֮��
#include <ansi.h>
#include <weapon.h>
inherit SWORD;
inherit F_UNIQUE;

void create()
{
        set_name(HIB"ˮ��ذ��"NOR, ({"water jian", "watersword"}));
        set_weight(15000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIB"����һ��ˮ��ذ��,�������侫�¡�������ˮ�������!\n"NOR);
                set("unique", 1);
                set("value", 50000);
                set("treasure",1);       
                                set("no_give",1);
                set("no_get",1);
                set("no_put",1);

                set("wield_neili", 2000);
                set("wield_maxneili", 3000);
                set("wield_str", 30);        
                set("treasure",1);       
                set("wield_msg",HIB"һ����ɫ�Ĺ�â���� ��$N�����϶����һ��ˮ��ذ�ס�\n"NOR);
                set("unwield_msg",HIB"$N�������е�ˮ��ذ�ס���ɫ�Ĺ�âҲ������ʧ�ˡ�\n"NOR);
        }
     init_sword(670);
        setup();
}       

mixed hit_ob(object me, object victim, int damage_bonus)
{
int a;
 if (victim->query("magicgift")==1
 && random(3)==0)
{
a = (int)me->query_skill("magic-water", 1);
a=320+a*2;
if (victim->query("qi") > a)
                victim->receive_damage("qi", a);
a=320+a;
if (victim->query("eff_qi") > a)
                victim->receive_wound("qi", a);
message_vision(HIB"$n��ˮ��ذ���Ϸ����ı���������!!\n"NOR, me,victim);
}
}