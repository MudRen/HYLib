#include <ansi.h>
#include <dbase.h>
#include <armor.h>

//inherit F_UNIQUE;
inherit NECK;

int do_wear(string arg);
int do_remove(string arg);
object offensive_target(object me);

void create()
{
        set_name(HIY"ʥ����"NOR, ({"sheng lingzhu"}) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "crystal");
                set("value",100000);
set("no_steal",1);
                set("no_get", "���ˣ�������ĳ�����\n");
//                set("no_give", "����ϡ��֮����ô������������?\n");
                set("no_sell", "��?����ϡ��֮��˭�����!\n");
                set("long","��س���ʱ�����߹����ϣ����߹����£���һ�ְ�����ǹ����У���Ϊ�˱���\n
������н�Ϊ���ӡ�\n");
                set("replace_file", __DIR__"rose");
                set("armor_prop/armor", 800);
                set("spells/fire", 1);
                set("spells/thunder",1);
                set("spells/water",1);
                set("spells/wind",1);
                set("spells/earth",1);
        }
        setup();
}

int init()
{
        object who = this_player();
        add_action("do_wear","wear");
        add_action("do_remove", "remove");
}

// This function selects a random target for offensive spells/functions.
object offensive_target(object me)
{
        int sz;
        object *enemy;

        enemy = me->query_enemy();
        if( !enemy || !arrayp(enemy) ) return 0;

        sz = sizeof(enemy);
        if( sz > 4 ) sz = 4;

        if( sz > 0 ) return enemy[random(sz)];
        else return 0;
}

int do_wear (string arg)
{
  object me = this_player();
  object zhu = this_object();
  string name = zhu->query("name");
  string msg;

if(arg!="all"&&arg != "sheng lingzhu" )
    return notify_fail("��Ҫ���ʲô��\n");
	if (me->is_busy())
		return notify_fail("����æ���ء�\n");

  msg = "$N����һ��"+name+"���ٸ�������ˬ��\n"; 
if (me->is_fighting())
{
  me->start_busy(2);
}

  zhu->set("wear_msg",msg);
remove_call_out("shengzhuconditions");
call_out("shengzhuconditions",1,me,zhu);
  return 0;
}

int do_remove (string arg)
{
  object me = this_player();
  object zhu = this_object();
  string name = zhu->query("name");
  string msg;

if ( arg!= "all" && arg != "sheng lingzhu")
    return notify_fail("��Ҫժ��ʲô��\n");

if (me->is_busy())
	return notify_fail("����æ���ء�\n");

  msg = "$N��"+name+"�����ժ��������\n"; 
if (me->is_fighting())
{
  me->start_busy(2);
}
  zhu->set("unequip_msg",msg);
remove_call_out("shengzhuconditions");
  return 0;
}

void shengzhuconditions(object who,object ob)
{
     object target;
     object me = this_player();
     int ap,dp,damage;
     string msg;
          
string type;
type = ob->query("armor_type");
if (!who) return;
if (who)
{
if( who->query_temp("armor/" + type) && ob->query("equipped")!="worn")
return;
}
if(me->query("combat_exp")>500000 )
{
  if( who->is_fighting())
     {
        target = offensive_target(who);
  if( ! target ) return ;      
 if( ! present( target,environment(who)) ) return ;    
        msg = HIR"ʥ������ʺ�����Ȼ���䣬ɲʱ�����׵�������ɽ�����ѣ�\n"NOR;
//divid by 10;

                ap = me->query("combat_exp");
                dp = target->query("combat_exp");
                        
                        
                if( random(ap) > dp/2 )
                 {
                        damage = 1200+random(800);
                        damage -= random((int)target->query("eff_jing") / 5);

                        if( damage > 0 ) 
                        {
                                msg += HIC "���$n��ܲ��������׵��������ţ��ֱ��ػ��յ�Ƥ�����á�\n
��ɽʯ�ҵ�Ƥ��Ѫ��������������˫�ۣ��ֱ�ˮ����͸�������������ѡ�\n" NOR;
if (damage> 1200) damage=1200;
                                target->receive_damage("jing", damage/2);
                                target->receive_wound("jing", damage/4);
                                target->receive_damage("qi", damage*8/5);
                                target->receive_wound("qi", damage/2);
                                target->start_busy(5);
                        } 
            else
//here, cast failed and the target's mana_factor will be added to the previous
//damage to hurt yourself:(...note damage<0.
                msg += HIC "\n˭֪$n���޷�Ӧ��\n" NOR;   
                }
                else
                        msg += "���Ǳ�$n�㿪�ˡ�\n";

                message_vision(msg, who, target); 
        }
call_out("shengzhuconditions",7,who,ob);
}
}

void owner_is_killed()
{
       destruct(this_object());
}
