// put.c
//����lywin 2000/6/14������bug

inherit F_CLEAN_UP;

int do_put(object me, object obj, object dest);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string target, item;
	object obj, dest, *inv, obj2;
	int i, amount;

	if(!arg) return notify_fail("��Ҫ��ʲô�����Ž����\n");

	if( me->is_busy() )
		return notify_fail("����һ��������û����ɣ�\n");
		

	if( sscanf(arg, "%s in %s", item, target)!=2 )
		return notify_fail("��Ҫ��˭ʲô������\n");

	dest = present(target, me);
	if( !dest || living(dest) ) dest = present(target, environment(me));
	if( !dest || living(dest) )
		return notify_fail("����û������������\n");

	if(sscanf(item, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, me)) )
			return notify_fail("������û������������\n");


	        if (obj==dest )
			return notify_fail("�Լ��Ž��Լ�?\n");
		if( !obj->query_amount() )
			return notify_fail( obj->name() + "���ܱ��ֿ���\n");
         	if( obj->query("dynamic_quest") )
			return notify_fail("����������ܷ�?\n");
         	if( obj->query("no_put") )
			return notify_fail("����������ܷ�?\n");

                if( obj->query("weapon_prop") && me->is_exert() &&
                        obj == me->query_temp("weapon"))
                if( obj->query("weapon_prop") && me->is_perform() &&
                        obj == me->query_temp("weapon"))
                               return notify_fail("������ʹ��"+me->query_perform()+"���޷�����"+obj->name()+"��\n");
		if( amount < 1 )
			return notify_fail("����������������һ����\n");
		if( amount > obj->query_amount() )
			return notify_fail("��û����ô���" + obj->name() + "��\n");
		else if( amount == (int)obj->query_amount() )
			return do_put(me, obj, dest);
		else {
			obj->set_amount( (int)obj->query_amount() - amount );
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
			return do_put(me, obj2, dest);
		}
	}

	if(item=="all") {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
			if( inv[i] != dest ) do_put(me, inv[i], dest);
		write("Ok.\n");
		return 1;
	}

	if(!objectp(obj = present(item, me)))
		return notify_fail("������û������������\n");
if (!obj) 		return notify_fail("������û������������\n");
if (!me) 		return notify_fail("������û������������\n");
	        if (obj==dest )
			return notify_fail("�Լ��Ž��Լ�?\n");

//	        if (obj->is_container() )
//			return notify_fail("���������ٷŽ�������\n");
//	        if (dest->is_container() )
//			return notify_fail("���������ٷŽ�������\n");

	return do_put(me, obj, dest);
}

int do_put(object me, object obj, object dest)
{
	if (!dest->is_container() )
	{
		tell_object(me, dest->name()+"�����������㲻�ܰѶ����Ž�ȥ��\n");
		return 1;
	}
        if (dest->is_character() &&
            sizeof(filter_array(all_inventory(dest), (: ! $1->query("equipped") :))) >= 30)
        {
                tell_object(me, dest->name() + "����Ķ���ʵ��"
                            "��̫���ˣ���û���ٷŶ����ˡ�\n");
                return 1;
        } else
        if (dest->is_container() && sizeof(all_inventory(dest)) >= 30)
        {
                tell_object(me, dest->name() + "����Ķ���ʵ��"
                            "��̫���ˣ����Ⱥú���������ɡ�\n");
                return 1;
        }

        if( obj->query("winner") )
	{
		tell_object(me, "�㲻�ܰ�"+obj->name()+"�Ž�ȥ��\n");
		return 1;
	}
	if( obj->query("no_get") )
	{
		tell_object(me, "�㲻�ܰ�"+obj->name()+"�Ž�ȥ��\n");
		return 1;
	}

	if( obj->query("dynamic_quest") )
	{
		tell_object(me, "�㲻�ܰ�"+obj->name()+"�Ž�ȥ��\n");
		return 1;
	}

	if( obj->query("no_put") )
	{
		tell_object(me, "�㲻�ܰ�"+obj->name()+"�Ž�ȥ��\n");
		return 1;
	}
	if( obj->query("id") == "corpse" )
	{
		tell_object(me, "�㲻�ܰ�"+obj->name()+"����ȥ��\n");
		return 1;
	}
        if(obj->is_character())
	{
		tell_object(me, "�㲻�ܰ�"+obj->name()+"����ȥ��\n");
		return 1;
	}

	if( userp(obj) )
	{
		tell_object(me, "�㲻�ܰ�"+obj->name()+"����ȥ��\n");
		return 1;
	}
        if( obj->query("weapon_prop") && me->is_exert() &&
            obj == me->query_temp("weapon"))
                 return notify_fail("������ʹ��"+me->query_exert()+"���޷�����"+obj->name()+"��\n");
        if( obj->query("weapon_prop") && me->is_perform() &&
            obj == me->query_temp("weapon"))
                 return notify_fail("������ʹ��"+me->query_perform()+"���޷�����"+obj->name()+"��\n");

	if( obj->move(dest) ) {
		message_vision( sprintf("$N��һ%s%s�Ž�%s��\n",
			obj->query("unit"), obj->name(), dest->name()),
			me );
		me->save();
		return 1;
	}
	else return 0;
}

int help(object me)
{
write(@HELP
ָ���ʽ : put <��Ʒ����> in <ĳ����>
 
���ָ��������㽫ĳ����Ʒ�Ž�һ����������Ȼ��������Ҫӵ��������Ʒ��
 
HELP
    );
    return 1;
}
