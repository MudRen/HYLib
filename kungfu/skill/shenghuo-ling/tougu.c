// tougu.c ͸����
// by snowman

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";
string *xue_name = ({ 
"�͹�Ѩ","����Ѩ","����Ѩ","��ԪѨ","����Ѩ","�м�Ѩ","�н�Ѩ","��ͻѨ","�ٻ�Ѩ",
"����Ѩ","����Ѩ","���Ѩ","�Ϲ�Ѩ","��ԨѨ","�쾮Ѩ","��ȪѨ","����Ѩ","����Ѩ",}); 
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

int perform(object me, object target)
{        
 object weapon;
//  mapping fam
        int damage,p;
	int extra,i;
        string msg, *limbs,name;
        weapon = me->query_temp("weapon");
    name = xue_name[random(sizeof(xue_name))];        
        if( !target) target = offensive_target(me);
        if( !target || !me->is_fighting(target) )
                return notify_fail("͸����ֻ����ս���жԶ���ʹ�á�\n");
	if( (int)me->query_skill("shenghuo-ling", 1) < 40 )
		return notify_fail("���ʥ���������죬ʹ������͸���롹�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
			return notify_fail("��ʹ�õ��������ԡ�\n");

        if( (int)me->query_skill("shenghuo-shengong",1) < 100 )
                return notify_fail("���ʥ���񹦵ȼ�����������ʩչ͸�����ھ���\n");
        if( (int)me->query_skill("force", 1) < 100 )
                return notify_fail("��Ļ����ڹ��ȼ�����������ʩչ͸�����ھ���\n");
        if( (int)me->query("neili") < 500 )
                return notify_fail("����������㣬����ʩչ͸�����ھ���\n");
        if( (int)me->query("jing") < 100 )
                return notify_fail("��ľ������㣬����ʩչ͸�����ھ���\n");

        tell_object(me, HIW"����������"HIB"͸����"HIW"����һ�ɼ�����������������һ�㣬��"+weapon->name()+"�ϴ�����ֱ��"+target->name()+"��\n"NOR);       
	extra = me->query_skill("qiankun-danuoyi",1) / 10;
if( (int)me->query_skill("qiankun-danuoyi", 1) > 149 )
{
	me->add_temp("apply/attack", (extra));	
	me->add_temp("apply/damage", (extra));
message_vision(HIG"\n$N��Ȼ����һ�䣬ֻ��һ���͸���룬�ֱ�Ϯ��$n���ߴ�ҪѨ��\n"NOR,me,target);
msg = HIW"��һö͸���룺"WHT"��"+(order[random(13)])+" "+xue_name[random(sizeof(xue_name))]+" "WHT"��\n" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
i=1;
if( (int)me->query_skill("qiankun-danuoyi", 1) > 159 )
{
msg = HIM"�ڶ�ö͸���룺"WHT"��"+(order[random(13)])+" "+xue_name[random(sizeof(xue_name))]+" "WHT"��\n" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
i=2;
}
if( (int)me->query_skill("qiankun-danuoyi", 1) > 169 )
{
msg = MAG"����ö͸���룺"WHT"��"+(order[random(13)])+" "+xue_name[random(sizeof(xue_name))]+" "WHT"��\n" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
i=3;
}
if( (int)me->query_skill("qiankun-danuoyi", 1) > 179 )
{
msg = YEL"����ö͸���룺"WHT"��"+(order[random(13)])+" "+xue_name[random(sizeof(xue_name))]+" "WHT"��\n" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
i=4;
}
if( (int)me->query_skill("qiankun-danuoyi", 1) > 189 )
{
msg = HIB"����ö͸���룺"WHT"��"+(order[random(13)])+" "+xue_name[random(sizeof(xue_name))]+" "WHT"��\n" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
i=5;
}
if( (int)me->query_skill("qiankun-danuoyi", 1) > 199 )
{
msg = RED"����ö͸���룺"WHT"��"+(order[random(13)])+" "+xue_name[random(sizeof(xue_name))]+" "WHT"��\n" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
i=6;
}
if( (int)me->query_skill("qiankun-danuoyi", 1) > 249 )
{
msg = HIR"���һö͸���룺"WHT"��"+(order[random(13)])+" "+xue_name[random(sizeof(xue_name))]+" "WHT"��\n" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
i=7;
}
	me->add_temp("apply/attack", -(extra));
	me->add_temp("apply/damage", -(extra));
me->add("neili", -i*60);
me->start_busy(i/2+1);
message_vision(WHT"\n$N�����ٱ䣬���ó�һö͸���룡\n"NOR,me,target);        
}
        if(random(me->query_skill("force")) > target->query_skill("force")/3){           
           damage = me->query_skill("force");
           damage = damage/2 + random(damage);
           if(target->query_skill("force")-50 > me->query_skill("force"))
             damage = damage/2;            
           if(target->query_skill("force") > me->query_skill("force")*2)
             damage = random(10);
           if(me->query_skill("force") > target->query_skill("force")*2)
             damage = damage+random(damage);
           if(damage > 300)
              tell_object(target, HIB"\nͻȻ֮�䣬���ؿ�һʹ���ƺ���һö��ϸ�ļ������һ�¡���һ�´�ʹ
ͻ�������������Σ�ʵ���ʣ�һ�ɺ���ͻ����Ļ����񹦣�ֱ�����ķΣ�\n"NOR);
           else if(damage <= 10){
              damage = 10;
              tell_object(target, HIY"\nͻȻ֮�䣬���ؿ�һʹ���ƺ���һö��ϸ�ļ������һ�¡��Һ��㻤���񹦱�
��ȫ������������������˿��֮ϸ��ٿ�궸�����ѷ��ѵ���ȴҲ���㲻�ã�\n"NOR);
              tell_object(me, HIY"�����ˡ�͸���롱���ھ��������Է����Ǻ��������ĵֵ���������\n"NOR);
              }
           else tell_object(target, HIB"\nͻȻ֮�䣬���ؿڱ��������һ�¡���ʹ�����Σ�ʵ���ʣ�һ�ɺ���ͻ�����
�����񹦣�ֱ�����࣡�������壬������ʧ������һ�̿ɵ�����ʹ��ǣ�\n"NOR);
           target->receive_damage("qi", damage);
           target->receive_wound("qi", damage);
           target->add("neili", -damage/2); 
           limbs = target->query("limbs");
           p = (int)target->query("qi")*100/(int)target->query("max_qi");
           tell_room(environment(target), HIR + target->name()+"ͻȻȫ��һ������ͬ���������һ�£�\n" NOR, ({ target }));  
           msg = damage_msg(damage, "����");
           msg += "( $n"+eff_status_msg(p)+" )\n";
           message_vision(msg, me, target);
           me->start_busy(2);
           me->add("neili", -150);
           if (!target->is_busy())
           target->start_busy(random(3));
           return 1;
           }
         
     else {
          me->add("neili", -50);
          tell_object(me, HIY"���͸�����ھ���û����"+target->name()+"���Ѿ�ɢ�ˡ�\n"NOR);
          me->start_busy(2);         
          }
        return 1;
}
