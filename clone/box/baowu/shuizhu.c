#include <ansi.h>
#include <dbase.h>
#include <armor.h>

inherit F_UNIQUE;
inherit NECK;

int do_wear(string arg);
int do_remove(string arg);
object offensive_target(object me);

void create()
{
        set_name(HIW "ˮ����" NOR, ({"shui lingzhu", "shuizhu"}) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "crystal");
                set("value",10000);
set("no_steal",1);
                set("no_give", "����ϡ��֮����ô������������?\n");
                set("no_sell", "��?����ϡ��֮��˭�����!\n");
                set("long","��˵�е����б���֮һ����֮�ɱ�ˮ�ͣ����ɷ���ˮϵ������\nΪ����������֮�");
                set("replace_file", __DIR__"rose");
                set("armor_prop/armor", 100);
                set("bb",1);
                set("spells/water", 1);
        }
        setup();
}

int init()
{
        add_action("do_wear","wear");
        add_action("do_remove", "remove");
        return 1;
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

if(arg!="all" && arg != "shuizhu" &&  arg != "shui lingzhu" )
    return notify_fail("��Ҫ���ʲô��\n");
	if (me->is_busy())
		return notify_fail("����æ���ء�\n");

  msg = "$N����һ��"+name+"�����鷢��ҫ�۵İ׹⣬�þòŰ�������\n"; 
if (me->is_fighting())
{
  me->start_busy(2);
}

  zhu->set("wear_msg",msg);
remove_call_out("shuizhuconditions");
call_out("shuizhuconditions",1,me,zhu);
  return 0;
}

int do_remove (string arg)
{
  object me = this_player();
  object zhu = this_object();
  string name = zhu->query("name");
  string msg;

if(arg!="all" && arg!="shuizhu"&&arg!="shui lingzhu")
    return notify_fail("��Ҫժ��ʲô��\n");

	if (me->is_busy())
		return notify_fail("����æ���ء�\n");

  msg = "$N��"+name+"�����ժ��������\n"; 
if (me->is_fighting())
{
  me->start_busy(2);
}

  zhu->set("unequip_msg",msg);
  remove_call_out("shuizhuconditions");
  return 0;
}

void shuizhuconditions(object who,object ob)
{
string type;
     object target;
     int ap,dp,damage;
     string msg;
          
type = ob->query("armor_type");
if (!who) return;
if( who->query_temp("armor/" + type) && ob->query("equipped")!="worn")
return;
  if( who->is_fighting())
     {
        target = offensive_target(who);
   if( ! target ) return ;      
 if( ! present( target,environment(who)) ) return ;    
        msg = HIC"ˮ���鶸�ְ׹⣬����к����ֳ������������͵����Ǳ�����������һ�£�\n
�����溮�ޱȵ�ˮ������$n��ȥ��\n"NOR;
//divid by 10;

                ap = who->query("combat_exp")/2;
                dp = target->query("combat_exp");
                        
                        
                if( random(ap) > dp/2 )
                 {
                        damage = 500+random(700);
                        damage -= random((int)target->query("eff_jing") / 5);

                        if( damage > 0 ) 
                        {
                                msg += HIC "���$n��ܲ�������ˮ���������ţ�\n" NOR;
if (damage> 800) damage=800;
                                target->receive_damage("jing", damage*4/5);
                                target->receive_wound("jing", damage/3);
                                target->receive_damage("qi", damage*4/5);
                                target->receive_wound("qi", damage/4);
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
call_out("shuizhuconditions",7,who,ob);
}

void owner_is_killed()
{
       destruct(this_object());
}
