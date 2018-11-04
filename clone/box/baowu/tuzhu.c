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
        set_name(HIY "������" NOR, ({"tu lingzhu", "tuzhu"}) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "crystal");
set("no_steal",1);
                set("value",10000);
                set("no_give", "����ϡ��֮����ô������������?\n");
                set("no_sell", "��?����ϡ��֮��˭�����!\n");
                set("long","��˵�е����б���֮һ����֮�ɱ�ʯ�ң����ɷ�����ϵ������\nΪ����������֮�");
                set("replace_file", __DIR__"rose");
                set("bb",1);
                set("armor_prop/armor", 100);
                set("spells/earth", 1);
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

if(arg!="all" && arg != "tuzhu" &&  arg != "tu lingzhu" )
    return notify_fail("��Ҫ���ʲô��\n");
	if (me->is_busy())
		return notify_fail("����æ���ء�\n");
  msg = "$N����һ��"+name+"����ɫ�ı�������ǰһ��һ���ġ�\n"; 
if (me->is_fighting())
{
  me->start_busy(2);
}

  zhu->set("wear_msg",msg);
remove_call_out("tuzhuconditions");
call_out("tuzhuconditions",1,me,zhu);
  return 0;
}

int do_remove (string arg)
{
  object me = this_player();
  object zhu = this_object();
  string name = zhu->query("name");
  string msg;

if (arg != "all" && arg != "tuzhu" && arg != "tu lingzhu")
    return notify_fail("��Ҫժ��ʲô��\n");

	if (me->is_busy())
		return notify_fail("����æ���ء�\n");

  msg = "$N��"+name+"�����ժ��������\n"; 
if (me->is_fighting())
{
  me->start_busy(2);
}

  zhu->set("unequip_msg",msg);
  remove_call_out("tuzhuconditions");
  return 0;
}

void tuzhuconditions(object who,object ob)
{
     object target;
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
if (!who) return;
  if( who->is_fighting())
     {
        target = offensive_target(who);
        if( ! target ) return ;
 if( ! present( target,environment(who)) ) return ;    
        msg = HIY"������ȽȽ����$n��ͷ�ϳ���һ���޴��ʯɽ��ֻ��������һ����\n
ʯɽ�������䣡\n"NOR;
//divid by 10;

                ap = who->query("combat_exp")/2;
                dp = target->query("combat_exp");
                        
                        
                if( random(ap) > dp/2 )
                 {
                        damage = 500+random(800);
                        damage -= random((int)target->query("eff_jing") / 5);

                        if( damage > 0 ) 
                        {
                                msg += HIC "���$n��ܲ�������ʯɽ�Ҹ����ţ�ͷ��Ѫ����\n" NOR;
if (damage> 800) damage=800;
                                target->receive_damage("jing", damage);
                                target->receive_wound("jing", damage/3);
                                target->receive_damage("qi", damage);
                                target->receive_wound("qi", damage/3);
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
call_out("tuzhuconditions",7,who,ob);
}

void owner_is_killed()
{
       destruct(this_object());
}
