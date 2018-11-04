// drop.c
// ����2000/6/14����bug

inherit F_CLEAN_UP;
#include <ansi.h>
int do_drop(object me, object obj);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object obj, *inv, obj2;
	int i, amount;
	string item;
string wiz_status;
	if(!arg) return notify_fail("��Ҫ����ʲô������\n");

	if(sscanf(arg, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, me)) )
			return notify_fail("������û������������\n");
		if( stringp(obj->query("no_drop")) )
			return notify_fail( (string)obj->query("no_drop") );
        if (userp(me) && !query_heart_beat(me))
        {
         "/cmds/usr/quithy"->main(me);
         write("������û�������������µ�½!!\n");
        }
        if( me->is_busy() )
        return notify_fail("����һ��������û����ɣ����ܶ�������\n");
      if( !environment(me) )
        return notify_fail("���ﲻ׼�Ӷ�����\n");

      if( environment(me)->query("no_drop1") )
        return notify_fail("���ﲻ׼�Ӷ�����\n");

		if( amount < 1 )
			return notify_fail("����������������һ����\n");
		if( amount > obj->query_amount() )
			return notify_fail("��û����ô���" + obj->name() + "��\n");
		else if( amount == (int)obj->query_amount() )
			return do_drop(me, obj);
		else {
			obj->set_amount( (int)obj->query_amount() - amount );
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
			return do_drop(me, obj2);
		}
	}

	if(arg=="all") {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++) {
			do_drop(me, inv[i]);
		}
		write("Ok.\n");
		return 1;
	}

	if(!objectp(obj = present(arg, me)))
		return notify_fail("������û������������\n");
	return do_drop(me, obj);
}

int do_drop(object me, object obj)
{
string wiz_status;
    object *inv;
	mixed no_drop;

	if( obj->query_temp("is_rided_by") == me->query("id"))
		return notify_fail( obj->name() + "�������������š�\n");
        if( obj->query("weapon_prop") && me->is_exert() &&
            obj == me->query_temp("weapon"))
                 return notify_fail("������ʹ��"+me->query_exert()+"���޷�����"+obj->name()+"��\n");
        if( obj->query("weapon_prop") && me->is_perform() &&
            obj == me->query_temp("weapon"))
                 return notify_fail("������ʹ��"+me->query_perform()+"���޷�����"+obj->name()+"��\n");

	if( no_drop = obj->query("no_drop") )
		return notify_fail( stringp(no_drop) ? no_drop : "���������������ⶪ����\n");
	inv = all_inventory(environment(me));  
        if (sizeof(inv)>49)
            return notify_fail("�����Ѿ���ô�ණ���ˣ�������\n");

/*        if( me->is_busy() )
                return notify_fail("����һ��������û����ɣ����ܶ�������\n");*/
	if( no_drop = environment(me)->query("no_drop") )
		return notify_fail( stringp(no_drop) ? no_drop : "���ﶫ��������ȥҲ��������\n");

if (userp(obj) &&
!environment(me)->query("no_fight"))
                        return notify_fail("Ҫ���»��˵���ң�����һ����ȫ�ĵط���\n");

	wiz_status = SECURITY_D->get_status(me);
	if( wiz_status != "(admin)" 
	&& userp(me) && wizardp(me))
message("channel:chat", HIC"����Ҽල��"+me->name() + "������" + 
                  obj->query("name")+HIC"!"NOR"��\n", users());

	if (obj->move(environment(me))) {
		if( obj->is_character() )
 if (!me->is_ghost())
{
			message_vision("$N��$n�ӱ��Ϸ������������ڵ��ϡ�\n", me, obj);
}else 			message_vision("$n��$N���ϵ������������ڵ��ϡ�\n", me, obj);
		else {
			message_vision( sprintf("$N����һ%s$n��\n",	obj->query("unit")),
				me, obj );
			if( !obj->query("value") && !obj->value() ) {
				write("��Ϊ������������ֵǮ���������ǲ�����ע�⵽���Ĵ��ڡ�\n");
				destruct(obj);
			}
/*			if( obj->query("id")=="coin" && !userp(obj)
			&& obj->query("money_id")=="coin" ) {
				write("��Ϊ������������ֵǮ���������ǲ�����ע�⵽���Ĵ��ڡ�\n");
				destruct(obj);
			}*/

		}
		me->save();
		return 1;
	}
	return 0;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : drop <��Ʒ����>
 
���ָ��������㶪������Я������Ʒ.
 
HELP
    );
    return 1;
}
 
