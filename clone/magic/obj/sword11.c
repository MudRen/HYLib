// ����֮��
#include <ansi.h>
#include <weapon.h>
inherit SWORD;
inherit F_UNIQUE;

void create()
{
        set_name(RED"��֮��"NOR, ({"fire jian", "firesword"}));
        set_weight(15000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", RED"����һ��ħ��֮��,�������侫�¡������л��׵�����!\n"NOR);
                set("unique", 1);
                set("value", 500000);
                set("treasure",1);       
                set("no_give",1);
                set("no_get",1);
                set("no_put",1);
                
                set("wield_neili", 2000);
                set("wield_maxneili", 3000);
                set("wield_str", 30);        
                set("treasure",1);       
                set("wield_msg",RED"һ����׵Ĺ�â���� ��$N�����϶����һ��ħ��֮����\n"NOR);
                set("unwield_msg",RED"$N�����еĹ⽣���뽣�ʡ�ħ���Ĺ�âҲ������ʧ�ˡ�\n"NOR);
        }
     init_sword(660);
        setup();
}       

mixed hit_ob(object me, object victim, int damage_bonus)
{
int a;
 if (victim->query("magicgift")==2
 && random(3)==0)
{
a = (int)me->query_skill("magic-fire", 1);
a=300+a*2;
if (victim->query("qi") > a)
                victim->receive_damage("qi", a);
a=300+a;
if (victim->query("eff_qi") > a)
                victim->receive_wound("qi", a);
message_vision(RED"$n����֮���Ϸ����Ļ���������!!\n"NOR, me,victim);
}
}