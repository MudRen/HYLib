void init()
{
	::init();
        add_action("do_kill","kill");
        add_action("do_kill","hit");    
}

int do_kill(string arg)
{
        object who = this_player();
        object me = this_object();
        
        if(!arg || present(arg,environment(me))!=me) return 0;
	if (!(me->query("ygjg")))
	    return 1;
	if (me->query("ygjg")!=who)
		return notify_fail(CYN"�㻹�Ǹ�˾��ְ��ר�ĶԸ����"HIR"�ɹű�"CYN"�ɡ�\n"NOR);
                message_vision(CYN"$N���ͣ�$N���ͣ�\n"NOR,who);
        return 1;
} 

