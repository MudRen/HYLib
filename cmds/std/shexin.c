// shexin.c

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        string dest, cmd, verb;
        object ob,obj;
        mapping fam;

        seteuid(getuid());

        if( environment(me)->query("no_fight") )
                return notify_fail("�����ֹս����\n");
        if( me != this_player() ) return 0;
        me = this_player();
        if ((!(fam = me->query("family")) || fam["family_name"] != "ѩɽ��"))
             return notify_fail("ֻ��ѩɽ���Ӳ�����ʹ��������\n");          
        if (me->query_skill("necromancy",1) < 40)
             return notify_fail("��Ľ�������̫ǳ���ˣ�û����ʹ��������\n");

        if( !arg || sscanf(arg, "%s to %s", dest, cmd) != 2 )
                return notify_fail("ָ���ʽ: shexin <ĳ��> to <ָ��>\n");

//      if (!ob = get_object( dest ) )
        if( !objectp(ob = present(dest, environment(me))))
                return notify_fail("�Ҳ���" + dest + "��\n");
        if( !living(ob) )
                return notify_fail("���������ܱ����ġ�\n");
        if( wiz_level(me) < wiz_level(ob) )
                return notify_fail("��û����" + ob->name() + "��ʹ��������\n");

	if( !ob->is_character() )
		return notify_fail("�����һ�㣬�ǲ��������\n");
	if(ob->query_temp("host"))
		return notify_fail("�㲻����������ˡ�\n");
	if(!userp(ob) && ob->query_leader())
		return notify_fail("�㲻����������ˡ�\n");

	if(userp(ob) &&  me->query("age")<18)
		return notify_fail("Ҫ����>600k,����>18����ʹ����������\n");

	if(userp(ob) && me->query("combat_exp")<600000)
		return notify_fail("Ҫ����>600k,����>18����ʹ����������\n");

	if(ob->query_temp("no_kill"))
		return notify_fail("�㲻����������ˡ�\n");

        if( ob->query("winner") )
		return notify_fail("���˲������ġ�\n");

	if( ob->query("tasknpc"))
		return notify_fail("���˲������ġ�\n");

        if (userp(me) && userp(ob)
         && ob->query_temp("nokill") )
        return notify_fail("������������ս�ƣ�\n");

        if (userp(me) && userp(ob)
         && me->query_temp("nokill") )
        return notify_fail("����������ս�ƣ�\n");
        
    if( userp(me) && userp(ob) && ob->query_condition("nokill")
    && !ob->query_condition("killer"))
        return notify_fail("�Ǹ��˸ձ�ɱ�����Ź����ɣ�\n");
if( !living(ob) && userp(ob) && ob->query("combat_exp")/2 > me->query("combat_exp") )
	return notify_fail("����Ҫɱ���ˣ���������ǿ̫�࣬�㲻�Ҷ��֡�\n");        
        if( ob->query("ownmake") )
                return notify_fail("���˲������ġ�\n");

//        if( ob->query("env/no_fight") )
//        return notify_fail("�������ģ����Ĳ��ð���\n");

    if( userp(ob) && ob->query("PKS")<=0 && me->query_condition("killer"))
        return notify_fail("���Ѿ���ͨ���ˣ���Ҫ����ɱ����ˣ�\n");
    if( userp(ob) && ob->query("combat_exp") < me->query("combat_exp") && me->query_condition("killer"))
        return notify_fail("���Ѿ���ͨ���ˣ���Ҫ����ɱ����ˣ�\n");


//��սϵͳ
obj=ob;
        if (userp(me) && userp(obj)
         && obj->query_temp("nokill") )
        return notify_fail("������������ս�ƣ�\n");

        if (userp(me) && userp(obj)
         && me->query_temp("nokill") )
        return notify_fail("����������ս�ƣ�\n");

    if( userp(me) && userp(obj) && obj->query_condition("nokill")
    && !obj->query_condition("killer"))
        return notify_fail("�Ǹ��˸ձ�ɱ�����Ź����ɣ�\n");
if( !living(obj) && userp(obj) && obj->query("combat_exp")/2 > me->query("combat_exp") )
	return notify_fail("����Ҫɱ���ˣ���������ǿ̫�࣬�㲻�Ҷ��֡�\n");

	if( ob->is_fighting() )
	return notify_fail("�����������������!\n");

	if( me->is_fighting() )
	return notify_fail("���������������!\n");

	if(ob->query("no_get"))
		return notify_fail("�㲻����������ˡ�\n");

 //&& strsrch(base_name(ob),"/quest/")>1
	if(!userp(ob)&& strsrch(base_name(ob),"quest") > 0)
//{
//        message_vision(HIG "�ļ���:"+base_name(ob)+"!\n" NOR, me);
		return notify_fail("���˺������йأ��������ġ�\n");
//}

//if (!userp(ob))
//return notify_fail("����BUG,�ݲ����Ŷ�NPC������!\n");
	if((int)ob->query("age") <= 18 && userp(ob))
		return notify_fail("Ϊ����������ã��Ź�С���Ӱ�.\n");

message_vision("
$N��һ���۾������ţ�ֻ������ϸ�죬��ϸ����ӨȻ�й⣬�����������ʡ�
$n΢�����ף�Ҫ��תͷ�ܿ�$N���۹⣬����һ˫�۾����Ʊ�$N��Ŀ����ס�ˣ�
��������������������\n", me, ob);
        if( random(me->query_skill("necromancy",1)) < random(ob->query_skill("force",1)))
        {
message_vision("ͻȻ$n�͵�һ�����ѣ����ǣ�$n���һ����������ˣ���������ʩ��������\n", me, ob);
                if( ob->query("age")>17) 
me->kill_ob(ob);
                ob->fight_ob(me);
                return 1;
        }

        if( !userp(ob) && me->query("combat_exp") < ob->query("combat_exp"))
        {
message_vision("ͻȻ$n�͵�һ�����ѣ����ǣ�$n���һ����������ˣ���������ʩ��������\n", me, ob);
                me->kill_ob(ob);
                ob->fight_ob(me);
                me->kill_ob(ob);
                return 1;
        }

        if (strsrch(cmd, "give ") >= 0)
        {
message_vision("���ǣ�$n���Ժ���Ҳ��֪���ǵ���Щʲô��$N��\n", me, ob);
        }
        else
        {
            if (strsrch(cmd, "go ") >= 0)
            {
message_vision("�����$n���Ժ���Ҳ��֪����ô���¾���ǰ�����߿��ˡ�\n", me, ob);
            }
            else
            {
                if (strsrch(cmd, "follow ") >= 0)
                {
message_vision("��Ȼ��$n���Ժ����ؾ͸���$N��ƨ�ɺ������ˡ�\n", me, ob);
                }
                else
return notify_fail("��ֻ�������˼�����give��go��follow��\n");
            }
        }
        if( wizardp(ob) )
return notify_fail("��ʦ���ܱ������ġ�\n");

        if( userp(ob) )
                log_file("shexin_player", sprintf("[%s] %s shexin %s to %s\n",
                        ctime(time()), geteuid(me), geteuid(ob), cmd));
        return ob->force_me(cmd);
}

int help(object me)
{
        write(@Help
 ָ���ʽ: shexin <ĳ��> to <ָ��>

 shexin sb to give sth to sb
 shexin sb to follow sb
 shexin sb to go <dir>

�����������ջ�ĳ���������ϵĶ�������, ���������뿪������
�����㡣��Ȼ�������ѩɽ�ɵ��ӣ������൱�Ľ�������Ϊ��
�Է�����ڹ���񣬶���ѧ�ղ�������ȻҲ�������������������ģ�
Help
        );
        return 1;
}

