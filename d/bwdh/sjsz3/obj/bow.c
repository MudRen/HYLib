//Cracked by Kafei
// bow.c for sjsz
// kane, 13/8/98
// sdong, modified it for sjsz

#include <ansi.h>
#include <weapon.h>

#ifdef AS_FEATURE
#include <dbase.h>
#else
inherit EQUIP;
#endif

private int shoot_result(object me, object victim, object ob);
mapping default_dirs = ([
        "north":        "��",
        "south":        "��",
        "east":         "��",
        "west":         "��",
        "northup":      "��",
        "southup":      "��",
        "eastup":       "��",
        "westup":       "��",
        "northdown":    "��",
        "southdown":    "��",
        "eastdown":     "��",
        "westdown":     "��",
        "northeast":    "����",
        "northwest":    "����",
        "southeast":    "����",
        "southwest":    "����",
        "up":           "��",
        "down":         "��",
        "out":          "��",
        "enter":        "��",
]);

void init()
{
        add_action("do_pull","pull");
        add_action("do_shoot","shoot");
	add_action("do_reload", "reload");
	add_action("do_reload", "load");
}

varargs void init_bow(int damage, int flag)
{
	if( clonep(this_object()) ) return;

	set("weapon_prop/damage", damage);
	set("flag", flag );
	set("skill_type", "archery");
	if( !query("actions") ) {
		set("actions", (: call_other, WEAPON_D, "query_action" :) );
		set("verbs", ({ "bash", "crush", "slam" }) );
	}
}

int do_reload(string arg)
{
	object me, ob, arrow, load_arrow;
	string str;	

	me = this_player();
	ob = this_object();

	if (!arg || !objectp(arrow = present(arg, me)) ) 
		return notify_fail("��Ҫ��ʲô���ڹ��ϣ�\n");
	
	if ( arrow->query("weapon_type") != "arrow" )
		return notify_fail("������ÿ����Ʒ�����Ե�����ġ�\n");
	
	if ( ob->query_temp("arrow_loaded") )
		return notify_fail("���Ѿ����ϼ��ˡ�\n");

	load_arrow = new(base_name(arrow));
	load_arrow->set_amount(1);

        if( arrow->query("poison_type") ) {
                ob->set("poison_applied", arrow->query("poison_applied"));
                ob->set("poison_type", arrow->query("poison_type"));
        }

        if( ob->query("pull_msg") )
                message_vision(ob->query("reload_msg"), me,arrow);
        else
                message_vision("$N��չ˫�ۣ���$n�������ڹ��ϡ�\n",me, load_arrow);

	
	ob->set("org_long", ob->query("long"));
	str = ob->query("long")+"�����Ѿ�����һ֧"+load_arrow->name()+"��\n";
	ob->set("long", str);

	ob->set_temp("arrow_loaded", load_arrow);
        
	if (arrow->query_amount() > 1)
                arrow->add_amount(-1);
        else destruct(arrow);
	return 1;
}
	
int do_pull(string arg)
{
        object me, ob;

        me = this_player();
        ob = this_object();

        if (arg != "bow" && arg != this_object()->query("id") )
                return command(query_verb()+" "+arg);

        if( (string)ob->query("equipped")!="wielded" )
                return notify_fail("�������Լ������к���\n");

	if( ob->query("broken"))
		return notify_fail("���Ź������Ѿ����ˡ�\n");

        if( ob->query("str_requirement") )
                if( me->query_str() < ob->query("str_requirement") )
                        return notify_fail("�������ԣ��������������Ź���\n");

        if( ob->query_temp("pulled") )
                return notify_fail("���Ѿ��ѹ������ˡ�\n");

	ob->add("wear_out", 1);

	if( ob->query("wear_out") > ob->query("bow_power")+random(10)){
		message_vision("$N����˫�ۣ�����������ֻ��ž��һ����$n�Ĺ��ұ������ˡ�\n", me, ob);
		ob->set("name", "�ϵ���"+ob->query("name"));
		ob->set("value", 0);
		ob->set("broken", 1);
		return 1;
	}
        if( ob->query("pull_msg") )

                message_vision(ob->query("pull_msg"), me,ob);
        else
             	message_vision("$N����˫�ۣ�������������ʱ��һ��$n������ͬ���¡�\n",me, ob);

        ob->set_temp("pulled", 1);

        return 1;
}

int do_shoot(string arg)
{
        object me, victim, ob, env, obj, arrow, where;
        string enemy, dir, dest, target;
        mapping exit;

        me = this_player();
        ob = this_object();

        env = environment(me);

        if(!env) return notify_fail("������Ҳ�䲻�ˡ�\n");

        if (env->query("pigging") || (env->query("short") == RED"����"NOR)
        || env->query("sleep_room") )
                return notify_fail("���ﲻ׼ս����\n");

        if( !arg || sscanf(arg, "%s at %s", enemy, dir) != 2 )
                return notify_fail("�����ʽ: shoot <ĳ��> at <����>��\n");

        if( (string)ob->query("equipped")!="wielded" )
                return notify_fail("���������㱳���ء�\n");

		  if( me->is_busy() )
                return notify_fail("��Ķ�����û����ɣ������䡣\n");

        if( !objectp(arrow = ob->query_temp("arrow_loaded") ) )
                return notify_fail("��û�����ô�䣿\n");

        if( !ob->query_temp("pulled") )
                return notify_fail("�㹭��û��������ô�䣿\n");

        if( !mapp(exit = env->query("exits")) || undefinedp(exit[dir]) ) {
                if( query_verb()=="shoot")
                        return notify_fail("��������䲻��ȥ��\n");
                else
                        return 0;
        }

        dest = exit[dir];

        if( !(obj = find_object(dest)) )
                call_other(dest, "???");
        if( !(obj = find_object(dest)) )
                return notify_fail("�޷��䡣\n");

        if( !undefinedp(default_dirs[dir]) )
					 target = default_dirs[dir];
		  else
					 target = obj->query("short");

		  if (obj->query("pigging") || (obj->query("short") == RED"����"NOR)
		  || obj->query("sleep_room") )
                return notify_fail("����׼֮����׼ս����\n");

        if( !objectp(victim = present(enemy, obj)) )
                return notify_fail("����׼֮��û�����Ŀ�ꡣ\n");

		  if (!living(victim))
					 return notify_fail("���Ŀ�겻�ǻ��\n");

		  if( ob->query("shoot_msg") )
					 message_vision(ob->query("shoot_msg"), me, victim);
		  else
					 message_vision(HIY"\n$N��ָһ�ɣ���ಡ���һ����" +target + "���$n���˹�ȥ������\n" NOR, me, victim);

		  ob->delete_temp("pulled");
	ob->delete_temp("arrow_loaded");
	ob->set("long", ob->query("org_long"));
	ob->delete("org_long");

		  if( arrow->query("shoot_msg") )
					 message_vision(arrow->query("shoot_msg"),arrow, victim);
		  else
                message_vision(HIR "\nֻ��һ֧��������$N�ƿռ������������\n" NOR,victim);

		  shoot_result(me,victim,arrow);
		  return 1;
}

private int shoot_result(object me, object victim, object ob)
{
		  object ob2, *inv;
		  string *limbs, str, dodge_skill, limb, result;
		  int i, embedded, ap, dp, damage, time, power, level, jiali;


	if( me->query("neili") > me->query("jiali") )
		jiali = me->query("jiali");
	else jiali = me->query("neili");
	me->add("neili", -jiali);

		  if( this_object()->query("bow_power") )
					 power = this_object()->query("bow_power");
		  else power = 20;
	level = me->query_skill("archery",1);
	if( level < 1 ) level = 20;

		  ap = me->query_str() - ob->query_weight()/200;
		  dp = victim->query_dex();
		  ap *= me->query("combat_exp")/1000;
		  ap *= power/20;
	if( !userp(victim) ) ap *= level/20;
		  dp *= victim->query("combat_exp")/1000;
		  ap = (ap+random(ap))/2;

		  victim->add_temp("offenders/"+me->query("id"), 1);

		  if ( ap > dp){
		  limbs = victim->query("limbs");
					 victim->receive_wound("qi", me->query_str(), me);
					 victim->receive_damage("qi", ob->query_weight()/100, me);

	if(!victim->query_temp("armor/embed")){
											ob2=new(base_name(ob));
											ob2->set_amount(1);
				 ob2->set("embedded",1);
											ob2->move(victim);
											ob2->do_embed();
											victim->receive_wound("qi",
				 power*ob->query("damage")+jiali*2, me);
					message_vision(CYN"���$Nһ���ҽУ�$n"+CYN+"��Ȼ����$N��"+limbs[random(sizeof(limbs))]
					+"�ϡ�\n"NOR, victim, ob);
		message_vision(HIR"��ԶԶ����"+victim->query("name")+"һ���ҽУ�"+ob->query("name")+"��Ȼ����"+victim->query("name")+"��"+limbs[random(sizeof(limbs))]+"�ϡ�\n"NOR,this_object());
	} else {
	//	ob2 = present("arrow", victim);
		ob2 = victim->query_temp("armor/embed");

		if ( ob2->query("weapon_type") == "arrow" ) {
			ob2->set_amount(ob2->query_amount()+1);
				message_vision(CYN"���$Nһ���ҽУ�$n"+CYN+"��Ȼ����$N��"+limbs[random(sizeof(limbs))]
				+"�ϡ�\n"NOR, victim, ob);
		} else {
			message_vision(CYN"$N�ƺ�һ����$n"+CYN+"��$N��"+limbs[random(sizeof(limbs))]
			+"����������һ��ƬƤ�⣬��Ѫ���죡\n"NOR, victim,ob);
			ob2 = new(base_name(ob));
			ob2->set_amount(1);
			ob2->move(environment(victim));
			message_vision(HIR"��ԶԶ����"+victim->query("name")+"�ƺ�һ����"+ob->query("name")+"��"+victim->query("name")+"��"+limbs[random(sizeof(limbs))]+"����������һ��ƬƤ�⣬��Ѫ���죡\n"NOR,this_object());
		}

		victim->receive_wound("qi",
					 power*ob->query("damage")+jiali*2, me);
					 }

					 me->start_busy(random(2));

		  result = COMBAT_D->eff_status_msg((int)victim->query("qi") * 100 /(int)victim->query("max_qi"));
		  message_vision("($N"+result+")\n", victim);
		  message_vision(HIR"��ԶԶ����("+victim->query("name")+result+")\n",this_object());

	if( this_object()->query("poison_type") ) {
					 victim->apply_condition(this_object()->query("poison_type"),
					 1+this_object()->query("poison_applied"));
					 this_object()->delete("poison_applied");
		this_object()->delete("poison_type");
		message_vision(RED"$N�ƺ������˿��е㷢����\n"NOR, victim);
		  }

	if( victim->query("combat_exp") >= me->query("combat_exp") * 2/3 )
		me->improve_skill("archery", me->query("int")/2);

	}

		  else if ( ap < dp/7 && ob->query_weight() < 7000
					 && victim->query("race") == "����"){
					 message_vision(CYN"����$N�����ֿ죬����һ�࣬��$n"+CYN+"����ؽ������\n\n"NOR, victim, ob);
					 me->start_busy(random(2));
					 if (ob->query_amount() > 0){
											ob->add_amount(-1);
											ob2=new(base_name(ob));
											ob2->set_amount(1);
											ob2->move(victim);
					 }
					 else ob->move(victim);

				message_vision(HIR"��ԶԶ����"+victim->query("name")+"���������ֿ죬����һ�࣬��"+ob->query("name")+"����ؽ������\n"NOR,this_object());
		  }

		  else {

		  dodge_skill = victim->query_skill_mapped("dodge");
					 if( !dodge_skill ) dodge_skill = "dodge";
					 str = SKILL_D(dodge_skill)->query_dodge_msg(limb);
					 message_vision(str, me, victim);

					 me->start_busy(random(2));
					 if (ob->query_amount() > 0){
                                 ob->add_amount(-1);
                                 ob2=new(base_name(ob));
                                 ob2->set_amount(1);
                                 ob2->move(environment(victim));
                }
		else ob->move(environment(victim));
		message_vision(HIR"��ԶԶ����"+victim->query("name")+"���������ֿ죬���Ӷ��һ�ࡣ\n"NOR,this_object());
      }
        return 1;
}

