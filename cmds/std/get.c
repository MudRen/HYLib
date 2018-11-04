// Filename : /cmds/verb/get.c

#include <ansi.h>

inherit F_CLEAN_UP;

int do_get(object me, object ob);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string from, item;
	object obj, *inv, env, obj2;
	int i, amount;
	string wiz_status;

	wiz_status = SECURITY_D->get_status(me);	
        if (userp(me) && !query_heart_beat(me))
        {
         "/cmds/usr/quithy"->main(me);
         write("������û�������������µ�½!!\n");
        }
      if( environment(me)->query("no_get") )
        return notify_fail("���ﲻ׼������\n");

	if( !arg ) return notify_fail("��Ҫ����ʲ�ᶫ����\n");
	if( me->is_busy() )
		return notify_fail("����һ��������û����ɣ�\n");

	// Check if a container is specified.
	if( sscanf(arg, "%s from %s", arg, from)==2 ) {
		env = present(from, me);
		if(!env) env = present(from, environment(me));
		if(!env) return notify_fail("���Ҳ��� " + from + " ����������\n");
        if( env->query_temp("no_kill") 
        && env->query("pubmaster"))
        return notify_fail("���˲���get��\n");

        if (userp(env) && !query_heart_beat(env))
        {
         write("������ʲô��\n");
        return notify_fail("������������\n");
        }
        if (userp(env) && env->query_temp("netdead"))
        {
         write("������ʲô��\n");
        return notify_fail("������������\n");
        }

	if( (env->query("no_get_from") || living(env) ) 
			&& (wiz_level(me) <= wiz_level(env)))
			return notify_fail("�����ʦ�ȼ�����ȶԷ��ߣ���������\n");
	if( userp(env) && query_ip_name(env)==query_ip_name(me) )
			return notify_fail("��ͬIP֮�䣬����������\n");


	if( (env->query("no_get_from") || living(env) ) 
	&& wiz_status != "(admin)" && wiz_status != "(arch)" && wiz_status != "(wizard)")
		return notify_fail("ֻ�� (wizard) ���ϵ���ʦ��������\n");

	} else env = environment(me);

	// Check if a certain amount is specified.
	if(sscanf(arg, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, env)) )
			return notify_fail("����û������������\n");
        if (userp(obj) && !query_heart_beat(obj))
		return notify_fail("�����ò�������\n");
        if (userp(obj) && !userp(me))
		return notify_fail("NPC���ܱ��ˡ�\n");

        if (userp(env) && env->query_temp("netdead"))
		return notify_fail("�����ò�������\n");
        if( obj->query_temp("no_kill") 
        && obj->query("pubmaster"))
		return notify_fail("�����ò�������\n");
        if( obj->query_temp("no_kill")
        && obj->query("pubmaster") )
		return notify_fail("�����ò�������\n");

		if( !obj->query_amount() )
			return notify_fail( obj->name() + "���ܱ��ֿ����ߡ�\n");
		if( amount < 1 )
			return notify_fail("�����ĸ���������һ����\n");
		if( amount > obj->query_amount() )
			return notify_fail("����û��������" + obj->name() + "��\n");
                if (me->query("combat_exp") <1000 
                      && userp(obj))
                      return notify_fail("ֻ�о������1000���ܱ���ҡ�Ŀǰ�㻹��������\n");
		else if( amount == (int)obj->query_amount() ) {
			return do_get(me, obj);
		} else {
			obj->set_amount( (int)obj->query_amount() - amount );
			obj2 = new(base_name(obj));
			obj2->move(env);			// For containers.
			obj2->set_amount(amount);
			// Counting precise amount costs more time.
			if( me->is_fighting() ) me->start_busy(4);
			return do_get(me, obj);
		}
	}

	// Check if we are makeing a quick get.
	if(arg=="all") {
		if( me->is_fighting() )	return notify_fail("�㻹��ս���У�ֻ��һ����һ����\n");
		if( !env->query_max_encumbrance() )	return notify_fail("�ǲ���������\n");
        if( env->is_tree() )
             return notify_fail("���Ǹ����ֻ����õģ����ǲ�Ҫ̫̰���˰ɣ\n");
        if (!userp(me) && env->is_character())
        return notify_fail("NPC������ʲô!\n");
        if (!userp(me) && userp(env))
        return notify_fail("NPC������ʲô!\n");
        if (userp(env) && !query_heart_beat(env))
		return notify_fail("�����ò�������\n");
        if (userp(env) && env->query_temp("netdead"))
		return notify_fail("�����ò�������\n");

 if(environment(me)->query("short")==BLU"ɽ��"NOR
       ||environment(me)->query("short")==WHT"����ʯ��"NOR
       ||environment(me)->query("short")==YEL"�Ҷ�"NOR
       ||environment(me)->query("short")==RED"���Ҷ�"NOR
       ||environment(me)->query("short")==CYN"ʯ��"NOR)
{
if (!userp(env) && env->is_character())
        return notify_fail("�Թ���������Ҫ����ʲô!\n");
}
		inv = all_inventory(env);
		if( !sizeof(inv) )
        {
            if( env->is_tree() )
               return notify_fail("����ʲôҲû���ˡ�\n");
			return notify_fail("������û���κζ�����\n");
        }

		for(i=0; i<sizeof(inv); i++) {
			if( inv[i]->is_character() || inv[i]->query("no_get") ) continue;
			do_get(me, inv[i]);
		}
		write("����ˡ�\n");
		return 1;
	}
if (userp(env)) env->save();
if (userp(me)) me->save();
	if( !objectp(obj = present(arg, env)) || living(obj) )
		return notify_fail("�㸽��û������������\n");
        if (!userp(me) && obj->is_character())
        return notify_fail("NPC������ʲô!\n");
        if (!userp(me) && userp(obj))
        return notify_fail("NPC������ʲô!\n");
        if (userp(obj) && !query_heart_beat(obj))
		return notify_fail("�����ò�������\n");
        if (userp(obj) && obj->query_temp("netdead"))
		return notify_fail("�����ò�������\n");

 if(environment(me)->query("short")==BLU"ɽ��"NOR
       ||environment(me)->query("short")==WHT"����ʯ��"NOR
       ||environment(me)->query("short")==YEL"�Ҷ�"NOR
       ||environment(me)->query("short")==RED"���Ҷ�"NOR
       ||environment(me)->query("short")==CYN"ʯ��"NOR)
{
if (!userp(obj) && obj->is_character())
        return notify_fail("�Թ���������Ҫ����ʲô!\n");
}
	if( obj->query("no_get") )
		return notify_fail("��������ò�������\n");
        if( obj->query("winner") )
		return notify_fail("�����ò�������\n");
        if( obj->query_temp("no_kill") 
        && obj->query("pubmaster"))
		return notify_fail("�����ò�������\n");
        if( obj->query_temp("no_kill")
        && obj->query("pubmaster"))
		return notify_fail("�����ò�������\n");
        if (!userp(me) && obj->is_character())
        return notify_fail("NPC������ʲô!\n");
        if (!userp(me) && userp(obj))
        return notify_fail("NPC������ʲô!\n");


	return do_get(me, obj);  
}
	
int do_get(object me, object obj)
{
	object old_env, *guard;
	int equipped;
        object *obs;

	if( !obj ) return 0;
	old_env = environment(obj);

	if( obj->is_character() ) {
		if( living(obj) ) return 0;
        
        if( obj->query_temp("no_kill") 
        && obj->query("pubmaster"))
		return notify_fail("�����ò�������\n");
        if (!userp(me) && obj->is_character())
        return notify_fail("NPC������ʲô!\n");
        if (!userp(me) && userp(obj))
        return notify_fail("NPC������ʲô!\n");

       if( userp(obj) && environment(obj)->query("short")=="�ؿ�" )
        return notify_fail("���ﲻ׼����ҡ�\n");
       if( userp(obj) && environment(obj)->query("short")=="ƽ����" )
        return notify_fail("���ﲻ׼����ҡ�\n");
       if( userp(obj) && environment(obj)->query("short")=="������" )
        return notify_fail("���ﲻ׼����ҡ�\n");
	if( userp(obj) && query_ip_name(obj)==query_ip_name(me) )
	return notify_fail("�㲻�ܱ���IP��ͬ����ҵ����塣\n");
 if(environment(me)->query("short")==BLU"ɽ��"NOR
       ||environment(me)->query("short")==WHT"����ʯ��"NOR
       ||environment(me)->query("short")==YEL"�Ҷ�"NOR
       ||environment(me)->query("short")==RED"���Ҷ�"NOR
       ||environment(me)->query("short")==CYN"ʯ��"NOR)
{
if (!userp(obj) && obj->is_character())
        return notify_fail("�Թ���������Ҫ����ʲô!\n");
}
		// If we try to save someone from combat, take the risk :P
	} else {
		if( obj->query("no_get") ) return 0;
	}

	if( guard = obj->query_temp("guarded") ) {
		guard = filter_array(guard, (:
			objectp($1) && present($1, environment($2)) && living($1) && ($1!=$2)
			:), me);
		if( sizeof(guard) )
			return notify_fail( guard[0]->name() 
				+ "������" + obj->name() + "һ�ԣ���ֹ�κ������ߡ�\n");
	}

	if( obj->query("equipped") ) equipped = 1;
        obs = filter_array(all_inventory(me), (: ! $1->query("equipped") :));
        if (sizeof(obs) >= 40 &&
            ! obj->can_combine_to(me))
                return notify_fail("�����ϵĶ���ʵ����̫���ˣ�û�����ö����ˡ�\n");

	if( obj->move(me) ) {
		if( me->is_fighting() ) me->start_busy(1);
		if( obj->is_character() )
			message_vision( "$N��$n�����������ڱ��ϡ�\n", me, obj );
		else
                 if(obj->query("dynamic_quest") || obj->query("dynamic_questjia"))
{
message("channel:chat", HIC"��������Ϣ��"GRN + me->query("name")+"�õ�"+HIR"����:" + obj->query("name")+HIG"����\n"NOR,users() );
}
			message_vision( sprintf("$N%sһ%s$n��\n", 
                
				old_env==environment(me)? "����":
					(old_env->is_character() ?
						"��" + old_env->name() + "����" + (equipped? "����" : "�ѳ�"):
                    (old_env->is_tree() ? "��" + old_env->name() +"��ժ��" :
						"��" + old_env->name() + "���ó�") ),
				obj->query("unit")), me, obj );
if (userp(old_env)) old_env->save();
if (userp(me)) me->save();
if (userp(me) && userp(old_env))
	log_file("cmds/get",
		sprintf("%s get %s from %s\n", me->query("name"), obj->query("name"),old_env->query("name")) );
		return 1;
	}
	else return 0;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : get <��Ʒ����> [from <������>]
 
���ָ��������������ϻ������ڵ�ĳ����Ʒ.
 
HELP
    );
    return 1;
}
 
