// qiankun-danuoyi.c Ǭ����Ų��
// by King 97.05

inherit SKILL;
#include "/kungfu/skill/eff_msg.h";
string  *msg_weapon = ({
YEL"$N����һ�ӣ�����б$w"YEL"���ƣ����ϵ���ô����һ��֮�����ػ�����������˴�����Ѱ����\n"NOR,
RED"��֪$N��$W"RED"΢ת��ƽƽ�Ĵ���$w"RED"֮�ϣ�һ����͵ľ����ͳ�����$w"RED"ֱ���˿�ȥ��\n"NOR,
HIY"$N����̤������������$W"HIY"�ӳ���һ�ɾ�������$n�ĺ��ģ���λʱ�������ǡ���ô���\n"NOR,
HIC"$n��������һ�У�ԭ�Ǽ�����������������$N��ָһ����������ббж�˿�ȥ��\n"NOR,
BLU"$N��$n��$w"BLU"��Ҫ�����Ŀ�ʱ������ͻȻ�߳���ѹ��$w"BLU"��һ����˳��̤�䣡\n"NOR,
HIB"$N˫��ͬʱʩչŲ��Ǭ���ķ���һ����Х����������ڰ��������һ��ת�ۣ�ƮȻ����$n���ԣ�\n"NOR,
HIW"$n�书��ߣ�����$N��������Ϯ�����������$w"HIW"��Ҳ���Բ��$N��$W"HIW"��ʽ��\n"NOR,
YEL"$N������ָ���縧�ٹ�ɪ�������������������������㲻����Ƭ�̼佫$n����������ж�ˣ�\n"NOR,
GRN"$N�Ҵ��һ��̩ɽ������������Ȫ��������ȴ��ʹ��Ǭ����Ų�Ƶ��ַ�������$n����$w"GRN"��\n"NOR,
CYN"$N����$W"CYN"������$n$w"CYN"���ϣ�����������Ǭ����Ų���ķ���΢һ�˾����㽫$n�ľ��������ƿ��ˣ�\n"NOR,
});

string  *msg_unarmed = ({
HIC"һɲ�Ǽ�$N����Ϊ��ļ���ת�ۣ���ʹ����Ǭ����Ų���ķ��ĵ��߲��񹦣�\n"NOR,
HIW"$N��Ҳ����������������ǰ��Ǭ����Ų������б������������Ų����ж�˿�ȥ��\n"NOR,
GRN"��֪�ո��ഥ��ͻȻһ����Ͷ����صľ�����$N���Ϸ�������ס��$n�ľ�����ͬʱ��$N������ָҲ�Ѱ���$n�ؿ�����Ѩ�����⣡\n"NOR,
RED"���$Nʹ��Ǭ����Ų���ķ������Ű��Է�λ��������$n���е�ȥ�ơ�\n"NOR,
CYN"$N��ʹǬ����Ų�ƣ�Խ��Խ�죬�����������Ƶ磬���������ǰ������̽��ץ��$n��\n"NOR,
BLU"$N��ʱ����������ת��һ����������Ȼ��Ȼ������������֮$n�����������ִ�ö��ˣ�\n"NOR,
BLU"$n����һָ����$N��ͷ��ȴ��֪��α�����һ�����۵�һ�죬���������Լ��ֱۣ�ֻʹ����ǰ����ֱð��\n"NOR,
YEL"���������Ա���һ��������������$n������һ������$N����бб������\n"NOR,
YEL"$N����Ǳ��Ǭ����Ų���ķ���ʹ$n����$N��һ��Ī��������ﻬ��һ�ԡ�\n"NOR,
HIR"$N��ʹŲ��Ǭ���ķ���һǣһ�����е�һ�죬��$n��������ƫ��\n"NOR,
YEL"$N������ָ���縧�ٹ�ɪ�����������������Σ������㲻������$n���л������Σ�\n"NOR,
WHT"$N����Ǭ����Ų���ķ���ʹ$n����Ī�����������;ת�˷��������������Σ�\n"NOR,
CYN"Ǭ����Ų���񹦱�ã��εȰ�����$N��ָ�������ѵ�����$n˫��Ѩ����\n"NOR,
GRN"$Nʹ��Ų�ƴ�Ǭ����$n����Ī�����������;ת�˷��򣬴�����������Լ����˻�����\n"NOR,
});
string *parry_msg = ({
	"$Nһ�л���$n���ϣ�ȴ��$n����Ǭ����Ų�ƣ�����������������¡�\n",
	"$n����һ����$N�����Լ������ػ��������ŵ������˼�����\n",
        "$n�ֱۻ�ת����$N����������һ�ƣ�$N������ա�\n",
        "$n�����������$N����������һ����$N���Ʋ�ס��ֱ��ǰ��ȥ��\n",
        "$n���β�����$Nһ�л��£�����ʯ���󺣣�������ס�ˡ�\n",
	"$n��ǣ������$N��������������ת�˺ü���Ȧ��\n",
	"$n˫�ֻ�Ȧ��$Nֻ����ǰ�������һ��ǽ����Ҳ������ȥ��\n",
	"$n����һת��$Nһ�л��ڵ��ϣ�ֻ��ó������\n",
});

string *dodge_msg = ({
	"$Nһ�л���$n���ϣ�ȴ��$n����Ǭ����Ų�ƣ�����������������¡�\n",
	"$n����һ����$N�����Լ������ػ��������ŵ������˼�����\n",
        "$n�ֱۻ�ת����$N����������һ�ƣ�$N������ա�\n",
        "$n�����������$N����������һ����$N���Ʋ�ס��ֱ��ǰ��ȥ��\n",
        "$n���β�����$Nһ�л��£�����ʯ���󺣣�������ס�ˡ�\n",
	"$n��ǣ������$N��������������ת�˺ü���Ȧ��\n",
	"$n˫�ֻ�Ȧ��$Nֻ����ǰ�������һ��ǽ����Ҳ������ȥ��\n",
	"$n����һת��$Nһ�л��ڵ��ϣ�ֻ��ó������\n",
});

int valid_enable(string usage) 
{ 
    return (usage == "parry") || (usage == "dodge");
}

string query_parry_msg(string limb)
{
       return parry_msg[random(sizeof(parry_msg))];
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}


int valid_learn(object me)
{
	int lvl = (int)me->query_skill("qiankun-danuoyi", 1);

	if ( me->query("gender") == "����" && lvl > 99)
		return notify_fail("�����첻�㣬��ѧ��ȥ�����߻���ħ��\n");

	if ((int)me->query_skill("force", 1) < 100)
		return notify_fail("����ô������ڹ�����ѧǬ����Ų�ƣ�\n");

	if (lvl > 150 && me->query("family/family_name") != "����" )
		return notify_fail("Ǭ����Ų��ֻ��ͨ����<<Ǭ����Ų��>>�ķ���ߡ�\n");


	if ((int)me->query("max_neili", 1) < 1500)
		return notify_fail("����ô����������ѧǬ����Ų�ƣ�\n");

        if ((int)me->query_skill("force", 1) < lvl)
                return notify_fail("��Ļ����ڹ���򻹲�����С���߻���ħ��\n");

        if ((int)me->query_skill("jiuyang-shengong", 1) < lvl)
                return notify_fail("��ľ����񹦻�򻹲�����С���߻���ħ��\n");

	if ((int)(me->query("max_neili")/15) < lvl)
		return notify_fail("���������򻹲�����С���߻���ħ��\n");

       if( me->query("family/family_name") != "����")
           return notify_fail("������̵��ӣ�ֻ��ͨ����<<Ǭ����Ų��>>�ķ���ߡ�\n");

        if ((int)me->query_skill("force", 1) < lvl)
                return notify_fail("��Ļ����ڹ���򻹲�����С���߻���ħ��\n");

        if ((int)me->query_skill("qingfu-shenfa", 1) < 80)
		return notify_fail("������������̫ǳ��\n");

        if ((int)me->query_skill("sougu", 1) < 80)
		return notify_fail("����ѹ�ӥצ�����̫ǳ��\n");

        if ((int)me->query_skill("hanbing-mianzhang", 1) < 80)
		return notify_fail("��ĺ������ƻ��̫ǳ��\n");
		
        if ((int)me->query_skill("jiuyang-shengong", 1) < lvl)
                return notify_fail("��ľ����񹦻�򻹲�����С���߻���ħ��\n");

	if ((int)(me->query("max_neili")/15) < lvl)
		return notify_fail("���������򻹲�����С���߻���ħ��\n");

        if ((int)me->query("qi") < lvl)
           return notify_fail("�������������Ǭ����Ų�ơ�\n");

        if ((int)me->query("jing") < lvl)
           return notify_fail("��ľ���������Ǭ����Ų�ơ�\n");

        if ((int)me->query("neili") < lvl)
           return notify_fail("��ľ���������Ǭ����Ų�ơ�\n");

if ( lvl > 149)
{
        me->receive_damage("jing", lvl/2);
        me->receive_damage("qi", lvl);
        me->add("neili", -lvl);
}
        return 1;
}


void skill_improved(object me)
{
   int skill, lit, med;
   skill = (int)me->query_skill("qiankun-danuoyi", 1);
   lit = (int)me->query_skill("literate", 1);
   med = me->query_skill("jiuyang-shengong", 1);
   if( skill == 50 && !me->query("qkdny") && lit > 50 && med > 50){
      tell_object(me, HIY"�㰴����Ƥ�����飬�������С��ƹ�ʹ�������Ǻ��������ı������ˡ�\n"NOR);
      me->add("max_neili", 10+random(30));
      me->set("qkdny", 1);
//      me->add("qkdny", 1);
      }
else if(skill == 80 && me->query("qkdny") == 1 && lit > 80 && med > 50){
      tell_object(me, HIM"�������ڶ����ķ�������ʩΪ��Ƭ��������ͨ��ֻ��ʮ����ָ֮�У��ƺ���˿˿���������\n"NOR);
      me->add("max_neili", 10+random(30));
      me->add("qkdny", 1);
      }
else if(skill == 100 && me->query("qkdny") == 2 && lit > 100 && med > 50){
      tell_object(me, CYN"�㰴����Ƥ�����飬�߶�����������Ϊ֮����\n"NOR);
      me->add("max_neili", 10+random(30));
      me->add("qkdny", 1);
      }
else  if(skill == 130 && me->query("qkdny") == 3 && lit > 120 && med > 50){
      message_vision(RED"$N��������͵�Ѫ�죬�������ȴ�����࣬���������㣬˫�۾��⾼���������ް���\n"NOR, me);
      me->add("max_neili", 10+random(30));
      me->add("qkdny", 1);
      }
else if(skill == 150 && me->query("qkdny") == 4 && lit > 140 && med > 50){
      message_vision(HIW"$N���Ϻ�����죬������ʱ����΢������麮�������Ϻ�ʱ��ͷ�������¡�\n"NOR, me);
      me->add("max_neili", 10+random(30));
      me->add("qkdny", 1);
      }
else if(skill == 170 && me->query("qkdny") == 5 && lit > 160 && med > 50){
      tell_object(me, MAG"���������Ǳ������ɽ��ͻ������ȻĪ֮������ԭ����Ǭ����Ų���ķ��������㱾�������е�Ǳ����\n"NOR);
      me->add("max_neili", 20+random(30));
      me->add("qkdny", 1);
      }
else if(skill == 190 && me->query("qkdny") == 6 && lit > 180 && med > 50){
      tell_object(me, MAG"���͵�����Ѫ��ӿ�������ӿ죬����������Ǭ����Ų���񹦣�\n");      
      me->add("max_neili", 50+random(30));
      me->add("qkdny", 1);
      }
}

int practice_skill(object me)
{
	int lvl = (int)me->query_skill("qiankun-danuoyi", 1);

        if( me->query("family/family_name") != "����")
           return notify_fail("������̵��ӣ�ֻ��ͨ����<<Ǭ����Ų��>>�ķ���ߡ�\n");

        if ((int)me->query_skill("force", 1) < lvl)
                return notify_fail("��Ļ����ڹ���򻹲�����С���߻���ħ��\n");

        if ((int)me->query_skill("jiuyang-shengong", 1) < lvl)
                return notify_fail("��ľ����񹦻�򻹲�����С���߻���ħ��\n");

	if ((int)(me->query("max_neili")/15) < lvl)
		return notify_fail("���������򻹲�����С���߻���ħ��\n");

        if ((int)me->query("qi") < lvl)
           return notify_fail("�������������Ǭ����Ų�ơ�\n");

        if ((int)me->query("jing") < lvl)
           return notify_fail("��ľ���������Ǭ����Ų�ơ�\n");

        if ((int)me->query("neili") < lvl)
           return notify_fail("��ľ���������Ǭ����Ų�ơ�\n");

        if ((int)me->query_skill("qingfu-shenfa", 1) < 80)
		return notify_fail("������������̫ǳ��\n");

if ( lvl > 149)
{
        me->receive_damage("jing", lvl/2);
        me->receive_damage("qi", lvl);
        me->add("neili", -lvl);
}
        return 1;
//	return notify_fail("Ǭ����Ų��ֻ��ͨ����<<Ǭ����Ų��>>�ķ���ߡ�\n");
}

string perform_action_file(string action)
{
        return __DIR__"qiankun-danuoyi/"  + action;
}

int ob_hit(object ob, object me, int damage)
{
        object wp,wp1, target;
        string msg;
        int p,j,skill, neili, neili1, exp, exp1;
        int level,level2,damage2;
        wp = me->query_temp("weapon");
        wp1 = ob->query_temp("weapon");
        skill = me->query_skill("qiankun-danuoyi", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
        exp = me->query("combat_exp");
        exp1 = ob->query("combat_exp");


        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("jiuyang-shengong",1);
        skill = me->query_skill("jiuyang-shengong", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");

if ( level2<= 0) level2= (int) me->query_skill("shenghuo-shengong",1);
damage2= (int) ob->query("neili",1)/10;
if (random(8)==0 && level2>=300 && (me->query_skill_mapped("force") == "jiuyang-shengong" || me->query_skill_mapped("force") == "shenghuo-shengong"))
{
j = -damage/2; 
j = 0;
if (damage2> 5000)	damage2=5000;
msg = HIC+"$N��������� ȫ���������������ֳ�һ����͵ľ���! !\n" +NOR;
           message_vision(msg, me, ob);
if ( me->is_busy())
{
me->start_busy(1);
ob->start_busy(2);
}
if (me->query("neili") > me->query("max_neili")*2)
{
		
		me->add("neili", damage2);
}


}

if (random(me->query_skill("jiuyang-shengong",1)) > 120
&& me->query("neili") < me->query("max_neili")
&& me->query_skill_mapped("force") == "jiuyang-shengong"
)

{
message_vision(HIR"$N��������񹦣�ȫ������ԴԴ���ϵ�ӿ��!\n"NOR,me, ob);
me->add("neili",random(me->query_skill("jiuyang-shengong",1))+200);
}

if (random(me->query_skill("jiuyang-shengong",1)) > 120
&& me->query("qi") < me->query("max_qi")
&& me->query_skill_mapped("force") == "jiuyang-shengong"
&& random(2)==0
)
{
message_vision(RED"$N��������񹦣����ϵ��˺��˺ܶ�!\n"NOR,me, ob);
me->add("qi",random(me->query_skill("jiuyang-shengong",1))+380);
if (me->query("eff_qi") < me->query("max_qi"))
me->add("eff_qi",random(me->query_skill("jiuyang-shengong",1))+380);
}



if (random(me->query_skill("qiankun-danuoyi",1)) > 120
&& me->is_busy()
&& me->query_skill_mapped("force") == "jiuyang-shengong"
&& random(2)==0)
{
message_vision(HIC"$N����Ǭ����Ų�ƣ�����æ�ҵĶ�����������!\n"NOR,me, ob);
me->start_busy(1);
}
      if(me->query_temp("yi_ob") && living(me)
      	&& me->query_skill_mapped("force") == "jiuyang-shengong"){
         target = present(me->query_temp("yi_ob"), environment(me));
         me->delete_temp("yi_ob");
         if(!target){
            tell_object(me, HIY"�㷢������Ų�Ƶ�Ŀ������Ѿ����������ˡ�\n"NOR);
            return damage;
            }
         if(!living(target)){
            tell_object(me, HIY"�㷢������Ų�Ƶ�Ŀ������Ѿ����Բ����ˡ�\n"NOR);
            return damage;
            }
         if(neili < 800){
            tell_object(me, HIY"����ҪŲ�ƣ�ȴ�����Լ������������ˣ�\n"NOR);
            return damage;
            }
         message_vision(WHT"$NͻȻ˫�ֻζ�������������������Ҵ�Ҫ��$n���������Ա�����ǣ����\n"NOR,me, ob);
         if(random(exp) < exp1/3){
            me->add("neili", -125);
            message_vision(HIY"���$n��û���ܵ����ţ�����˳������$N�Ĳ��棬����ǿ����һ����\n"NOR,me, ob);
            return random(damage);
            }
         me->add("neili", -250);
         tell_room(environment(me), "�������"+ob->name()+"������ֱ��"+target->name()+"�����ȥ��\n",({ target,ob }));
         tell_object(target, HIR"����㷢��"+ob->name()+"������ֱ���Լ����������\n"NOR);
         tell_object(ob, HIR"����㷢���Լ�������ֱ��"+target->name()+"�����ȥ��\n"NOR);
         if(target->query_skill("dodge")>=damage)
            msg = HIY"���$nû���ܵ��κ��˺���\n"NOR;
         else{
            target->receive_damage("qi", damage-target->query_skill("dodge"), ob);
            target->receive_wound("qi", damage-target->query_skill("dodge"), ob);
            p = target->query("qi")*100/target->query("max_qi");
            msg = damage_msg(damage/2, "�˺�");
            msg += "( $n"+eff_status_msg(p)+" )\n";
            }
         if(target->query("shen") < -1000 && !target->is_killing(ob->query("id"))){
              if(random(target->query_int()) < 20)
                   target->kill_ob(ob);
              else if(random(target->query_int()) > 30)
                   target->fight_ob(me);
              }
         if(target->query("shen") > -1000 && !target->is_killing(ob->query("id"))){
              if(random(target->query_int()) < 20)
                   target->fight_ob(ob);
              else if(random(target->query_int()) > 30)
                   target->fight_ob(me);
              }
         message_vision(msg, me, target);
         return -5000;
         }
      if(me->query_temp("fanzhen")){
           me->delete_temp("fanzhen");
           return 1;
           }
      if(me->query("jiali") && living(me) &&
         random(exp) < exp1/3 && skill > 50 && neili > 500 && living(ob)
         && !ob->query("env/invisibility")
         && me->query_skill_mapped("force") == "jiuyang-shengong"
         ){
         if(random(2)==1) me->add_temp("fanzhen", 1); 
         me->add("neili", -(random(10)));
        if(wp && wp1 && userp(me)){                    
           msg = msg_weapon[random(sizeof(msg_weapon))];
           msg = replace_string(msg, "$W", wp->name());
           msg = replace_string(msg, "$w", wp1->name());
           if(neili >= neili1*2+damage){
              if(random(me->query_str()) > ob->query_str()/2 && skill > 150){
                  msg += HIW"���$nһ���ֵ���ס������"+wp1->name()+HIW"���ַɳ���\n"NOR,
                  me->add("neili", -50);
                  wp1->unequip();
                  wp1->move(environment(ob));
                  j = -5000;
                  }
              else{
                  if (damage>50)
{
                  ob->receive_damage("qi", damage/2?damage/2:10, me);
                  ob->receive_wound("qi", damage/10 > 0?damage/10:2, me);
}
                  p = ob->query("qi")*100/ob->query("max_qi");
                  msg += damage_msg(damage/2, "�˺�");
                  msg += "( $n"+eff_status_msg(p)+" )\n";
                  j = -5000;
                  }
              }
           else if(neili >= random(neili1)*2+damage){
              msg += "���������ж����$n��������\n";              
              j = -5000;
              }
           else{
              j = damage/2+random(damage/2);
              if(j<damage/2) msg += "���ж����һЩ$n��������\n";
              else msg += "���ж����$n����������\n";
              j = -j;
              }           
           message_vision(msg, me, ob);
           return j;
           }          
        else{
           msg = msg_unarmed[random(sizeof(msg_unarmed))];
           if(neili >= neili1*2+damage){
if (damage>50)
{
              ob->receive_damage("qi", damage/2?damage/2:10, me);
              ob->receive_wound("qi", damage/10 > 0?damage/10:2, me);
}
              p = ob->query("qi")*100/ob->query("max_qi");
              msg += damage_msg(damage, "����");
              msg += "( $n"+eff_status_msg(p)+" )\n";
              j = -5000;
              }
           else if(neili >= random(neili1)*2+damage){
              msg += "���������ж����$n��������\n";              
              j = -5000;
              }
           else{
              j = damage/2+random(damage/2); 
              if(j<damage/2) msg += "���ж����һЩ$n��������\n";
              else msg += "���ж����$nһ���������\n";
              j = -j;
              }           
           message_vision(msg, me, ob);
           return j;
           }
     }
}