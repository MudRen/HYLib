// give.c
// ����2000/6/14����bug

#include <ansi.h>

inherit F_CLEAN_UP;

int do_give(object me, object obj, object who);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string target, item;
string wiz_status;
	object obj, who, *inv, obj2;
	int i, amount;

        if (userp(me) && !query_heart_beat(me))
        {
         "/cmds/usr/quithy"->main(me);
         write("������û�������������µ�½!!\n");
        }

	if(!arg) return notify_fail("��Ҫ��˭ʲô������\n");

	if( sscanf(arg, "%s to %s", item, target)==2
	|| sscanf(arg, "%s %s", target, item)==2 );
	else return notify_fail("��Ҫ��˭ʲô������\n");

	if(!objectp(who = present(target, environment(me))) || !living(who))
		return notify_fail("����û������ˡ�\n");

	if( me->is_busy() )
		return notify_fail("����һ��������û����ɣ�\n");

	if( who->query("env/no_accept")&&!wizardp(me) )
		return notify_fail("�˼����ڲ���Ҫʲô������\n");
	if(sscanf(item, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, me)) )	
			return notify_fail("������û������������\n");
	if( obj->query_temp("is_rided_by") == me->query("id"))
		return notify_fail( obj->name() + "���������ţ����ܸ��ˡ�\n");
if (userp(me) && !userp(who) && obj->is_character())
	return notify_fail("����ѻ�������??\n");

if (who->query("id")!="zhou botong" &&
who->query("id")!="shangguanjiannan")
{
	if( obj->query("no_give")&& obj->query("no_get")&&!wizardp(me))
			return notify_fail("�����������������ˡ�\n");

	if( obj->query("no_drop")&&!wizardp(me) )
			return notify_fail("�����������������ˡ�\n");
	if( obj->query("no_drop")&& obj->query("no_get")&&!wizardp(me) )
			return notify_fail("�����������������ˡ�\n");
	if( obj->query("no_get")&&!wizardp(me) )
			return notify_fail("�����������������ˡ�\n");

}
                if( obj->query("weapon_prop") && me->is_exert() &&
                        obj == me->query_temp("weapon"))
                               return notify_fail("������ʹ��"+me->query_exert()+"���޷�����"+obj->name()+"��\n");
                if( obj->query("weapon_prop") && me->is_perform() &&
                        obj == me->query_temp("weapon"))
                               return notify_fail("������ʹ��"+me->query_perform()+"���޷�����"+obj->name()+"��\n");
	if( obj->query("ownmake") && !wizardp(me) )
		return notify_fail("�����������������ˡ�\n");
	if( obj->query("jobfeng") )
		return notify_fail("�����������������ˡ�\n");

        if(obj->query("dynamic_quest") && !userp(me))
		return notify_fail("�����������������ˡ�\n");
		if( !obj->query_amount() )	
			return notify_fail( obj->name() + "���ܱ��ֿ����ˡ�\n");
		if( amount < 1 )
			return notify_fail("����������������һ����\n");
		if( amount > obj->query_amount() ) 
			return notify_fail("��û����ô���" + obj->name() + "��\n");

                // add by hello 1996.12.05
                // �����������ǲ�������̫����
                inv = all_inventory(who);
	wiz_status = SECURITY_D->get_status(me);
	if( wiz_status != "(admin)" 
	&& userp(me) && wizardp(me))
message("channel:chat", HIC"����Ҽල��"+me->name() + "��" + 
                  who->query("name") + "��"+obj->query("name")+HIC"!"NOR"��\n", users());

                if (inv && sizeof(inv)>49 && userp(who))
                {
                        write(who->name()+"���϶���ô�ණ���ˣ��㻹���������\n");
                        return 1;
                }
		else if( amount == (int)obj->query_amount() )
			return do_give(me, obj, who);
		else {
			obj->set_amount( (int)obj->query_amount() - amount );
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
			if (do_give(me, obj2, who))
				return 1;
			else {
				obj->set_amount((int)obj->query_amount() + amount);
				return 0;
			}
		}
	}

	if(arg=="all") {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++) {
			do_give(me, inv[i], who);
		}
		write("Ok.\n");
		return 1;
	}

	if(!objectp(obj = present(item, me)))
		return notify_fail("������û������������\n");
	return do_give(me, obj, who);
}

int do_give(object me, object obj, object who)
{
int exp,pot;
string wiz_status;
if (who->query("id")!="zhou botong")
{
	if( obj->query("no_give")&& obj->query("no_get")&&!wizardp(me))
			return notify_fail("�����������������ˡ�\n");

	if( obj->query("no_drop")&&!wizardp(me) )
			return notify_fail("�����������������ˡ�\n");
	if( obj->query("no_get")&& obj->query("no_drop") && !wizardp(me) )
			return notify_fail("�����������������ˡ�\n");
}
	if( obj->query("jobfeng") )
		return notify_fail("�����������������ˡ�\n");
        if (userp(who) &&
            sizeof(filter_array(all_inventory(who), (: ! $1->query("equipped") :))) >= 40 &&
            ! obj->can_combine_to(who))
        {
		tell_object(me, "�˼����ϵĶ���ʵ����̫���ˣ�û�����ö����ˡ�\n");
                return 0;
        }

	switch ((string)obj->query("equipped"))
	{
	case "worn":
		tell_object(me, obj->name() + "�������������ܸ����ˡ�\n");
                return 0;

	case "wielded":
                tell_object(me, obj->name() + "������װ�����ܸ����ˡ�\n");
                return 0;
	}

// Add by Java 
	if( userp(obj) )
		return notify_fail("��ֻ������ҡ�\n");
// on June 3.1998

	if( obj->query_temp("is_rided_by") == me->query("id"))
		return notify_fail( obj->name() + "�������������š�\n");

	if( me->is_busy() )
		return notify_fail("����һ��������û����ɣ�\n");
		// check for dynamic_quests
        if(obj->query("dynamic_quest"))
        if(TASK_D->quest_reward(me,who,obj))
        return 1;
        if(!userp(who)
 && obj->query("name")==me->query_temp("jobitem")
 && who->query("name")==me->query_temp("jobnpc")
 && !userp(obj))
{
exp=random(300)+390;
pot=exp*2/3+random(280);
me->add("potential",pot);
me->add("combat_exp",exp);
tell_object(me,HIW"�㱻�����ˣ�\n" + 
chinese_number(exp) + "��ʵս����\n" +
chinese_number(pot) + "��Ǳ��\n"+
NOR);
tell_object(me,HIR"��ɹ��������һ������!\n"+
NOR);

destruct(obj);
me->apply_condition("nonamejob",0);
me->delete_condition("nonamejob");
me->set("quest", 0);
me->delete_temp("jobnpc");
me->delete_temp("jobitem");
//return notify_fail(HIR"��ɹ��������һ������!��\n"NOR);
return 1;
}

	if( !interactive(who) && !who->accept_object(me, obj) )
//		return notify_fail("������������˼һ�����Ҫ�������������\n");
		return notify_fail("�Է�����������������\n");
/* 
       //��������¼��/log/cmds/give   ����(lywin)

	log_file("cmds/give",
	sprintf("%s(%s) ��%s��һ��(%s) ����%s��%s��on %s\n",
	me->name(),  //��¼ʹ�����������
	geteuid(me), //��¼ʹ�������ID
	(string)environment(me)->query("short"), //��¼������Ʒ���ڵķ���
	obj->name(1), //��¼������Ʒ������
	who->name(),  //��¼ʹ�ö��������
	geteuid(who), //��¼ʹ�ö����ID
	ctime(time()) ) ); //��¼ʹ�������ʱ��
*/

	wiz_status = SECURITY_D->get_status(me);
	if( wiz_status != "(admin)" && wiz_status != "(arch)" 
	&& userp(me) && wizardp(me))
message("channel:chat", HIC"����Ҽල��"+me->name() + "��" + 
                  who->query("name") + "��"+obj->query("name")+HIC"!"NOR"��\n", users());

	if( !userp(who) && obj->value() ) {
		message_vision("$N�ó�" + obj->short() + "��$n��\n", me, who);
if (!obj->query("money_id") || !who->query("pubmaster") || !who->query_temp("no_kill")  || obj->query("base_value") < 100)
{
		destruct(obj);
}
else
{
	obj->move(who);
}
        me->save();
        if (userp(who)) who->save();
		return 1;
	} else if( obj->move(who) ) {
		printf("���%sһ%s%s��\n", who->name(), obj->query("unit"),
			obj->name());
		message("vision", sprintf("%s����һ%s%s��\n", me->name(),
			obj->query("unit"), obj->name()), who );
		message("vision", sprintf("%s��%sһ%s%s��\n", me->name(), who->name(),
			obj->query("unit"), obj->name()), environment(me), ({me, who}) );
		me->save();
	if( !userp(who) && !obj->is_character()
	&& !userp(obj)) 
{
obj->set("no_beg",1);	
obj->set("no_steal",1);
}
		if (userp(who)) who->save();
		if (userp(obj)) obj->save();
		return 1;
	}
	else return 0;
}
int help(object me)
{
write(@HELP
ָ���ʽ : give <��Ʒ����> to <ĳ��>
      �� : give <ĳ��> <��Ʒ����>
 
���ָ��������㽫ĳ����Ʒ�����ˣ���Ȼ��������Ҫӵ��������Ʒ��
 
HELP
    );
    return 1;
}
