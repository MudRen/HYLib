// ����֮��
#include <ansi.h>
#include <weapon.h>
inherit SWORD;
inherit F_UNIQUE;

void create()
{
        set_name(BLK"����֮��"NOR, ({"dark jian", "darksword"}));
        set_weight(15000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", BLK"����һ�Ѱ���֮��,�������侫�¡���������Ų�֮һ!\n"NOR);
                set("unique", 1);
                set("value", 0);
		set("no_put", 1);
		set("no_put", 1);
		set("no_get", 1);
		set("no_drop", 1);
		set("no_pawn", 1);
                set("treasure",1);       
                        set("armor_prop/intelligence",15);
         set("armor_prop/strength",15);
                set("wield_neili", 2000);
                set("wield_maxneili", 3000);
                set("wield_str", 30);        
                set("skill", ([
                        "name": "magic-dark",
                        "exp_required": 20000000,
                        "difficulty": 300,
                        "min_skill":  500,
                             "max_skill": 1000,              
                ]) );
                set("armor_prop/attack", 50);	
                set("treasure",1);       
                set("wield_msg",BLK"һ��ڰ��Ĺ�â���� ��$N�����϶����һ�Ѱ���֮����\n"NOR);
                set("unwield_msg",BLK"$N�����еĹ⽣���뽣�ʡ��ڰ��Ĺ�âҲ������ʧ�ˡ�\n"NOR);
        }
     init_sword(1888);
        setup();
}       
void owner_is_killed()
{
       destruct(this_object());
}
int query_autoload()
{
       return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
int a;
if (1)
if (random(4)==0)
{
message_vision(BLK"$N���ϵİ���֮����ʹ��ձ����ڣ�һ��С�͵ĺڶ�������$n���Ͽգ�\n"NOR, me,victim);
message_vision(BLK"���ں�����!!  $n���������˺˱�����\n"NOR, me,victim); 
 if (random(2)==0)
{
a = (int)me->query_skill("magic-dark", 1);
a=600+a*3;
                victim->receive_damage("qi", a);
a=600+a;
                victim->receive_wound("qi", a);
message_vision(BLK"$n����û����ܣ�$n�������˺ڰ��ĺ˵���!!\n"NOR, me,victim);
}
else message_vision(HIR"$n����һЦ����ħ������һ��������������������ˡ�!\n"NOR, me,victim);
}
if (random(4)==1)
{
message_vision(BLK"$N���ϵİ���֮����ʹ��ձ�����,$n�����ĵط��¶�ͻȻ�½�,�����˱���ѩ��\n"NOR, me,victim);
message_vision(BLK"���ڱ���ѩ!!  $n���������˱���ѩ����\n"NOR, me,victim); 
 if (random(2)==1)
{
if (!victim->is_busy())
victim->start_busy(3);
message_vision(BLK"$n�ĸ�����Ϊ�˺ڰ��ı���!!$n����ȫ���ʹ������������!!\n"NOR, me,victim);
}
else message_vision(BLK"$n����Ծ���ӹ���һ�ѡ�!\n"NOR, me,victim);
}

}