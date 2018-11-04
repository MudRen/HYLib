// quit.c

#include <command.h>
#include <ansi.h>

inherit F_DBASE;
inherit F_CLEAN_UP;

void create() 
{
	seteuid(getuid());
	set("name", "����ָ��");
	set("id", "quit");
	set("channel_id", "���߾���");
}

int main(object me, string arg)
{
	int i;
	object *inv, link_ob, ob;
string name;
	if( LOGIN_D->get_madlock()) 
		return notify_fail("ʱ���Ѿ���գ�û�����ܹ��˳����ʱ���ˡ�\n");
//	if( me->is_busy()) return notify_fail("��������æ���������£������˳���Ϸ��\n");
	if (me->query_temp("sleeped")) me->set("marks/insleeping",1);
        if( !me->query_temp("netdead") && !interactive(me)) 
           return notify_fail("���ָ��ֻ����ϵͳִ�С�\n");
	if( interactive(me) && query_idle( me ) < 120 )
           return notify_fail("���ָ��ֻ����ϵͳִ�С�\n");
	
	if( me->over_encumbranced() )
		return notify_fail("���ϴ��Ķ���̫���ˣ��벻����Ϸ�ˡ�\n");
if (present("xin",me))
{
                   me->apply_condition("menpai_busy",8);
                   me->apply_condition("hxsd_busy",8);
}

	if( !wizardp(me) ) {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
			if( !inv[i]->query_autoload() )
				DROP_CMD->do_drop(me, inv[i]);
	}

	link_ob = me->query_temp("link_ob");

	// We might be called on a link_dead player, so check this.
	if( link_ob ) {
		link_ob->set("last_on", time());
		link_ob->set("last_from", query_ip_name(me));
		link_ob->save();

  	if( link_ob->is_character() ) {
			write("��Ļ��ǻص�" + link_ob->name(1) + "�����ϡ�\n");
			exec(link_ob, me);
			link_ob->setup();
			return 1;
		}
		

		link_ob->set("last_on", time());
		link_ob->set("last_from", query_ip_name(me));
		link_ob->save();
		if( environment(me)->query("valid_startroom") )
		{
			me->set("startroom", base_name(environment(me)));
			write("�����´����߽���ʱ��������￪ʼ��\n");
		}

		destruct(link_ob);
	}

	write("��ӭ�´�������\n");

//        if ( wiz_level( me->query("id") ) < 2 ){
//             message("channel:chat",HIW"������ͨ�桿��"
//             +me->query("name")+"("+me->query("id")+")��ʱ�뿪�˽�����\n"NOR,users());
//             }

//        message("system", me->name() + "�뿪��Ϸ��\n", environment(me), me);
        
//	i=me->query("combat_exp")-me->query_temp("temp_exp");
//	if (i < 0 ) i=0;
if (me->query("combat_exp") - me->query_temp("temp_exp") > 100)
{
	if (!wizardp(me)
	&& (i = (me->query("combat_exp") - me->query_temp("temp_exp")) * 60
		/ (me->query("mud_age") - me->query_temp("mud_age"))) > 100)
		log_file("static/EXP",
			sprintf("%s �ϴξ��飺%d�����ξ��飺%d��ƽ����%d/min\n",
				geteuid(me), me->query_temp("temp_exp"),
				me->query("combat_exp"), i));
}
	CHANNEL_D->do_channel(this_object(), "sys",
		me->name() + "(" + me->query("id") + ")�뿪��Ϸ�ˡ��������߾�������"+i+"��\n");
//	CHANNEL_D->do_channel(this_object(), "sys",
//		me->name() + "(" + me->query("id") + ")�뿪��Ϸ�ˡ������ " + reclaim_objects() + " ��������\n");
	
//if (present("xin",me))
//me->apply_condition("menpai_busy",6);
	me->save();

//************* Puff added these for update topten ***********
        if( userp(me) )
                if( !wizardp(me) )
                {
                        ob=new("/clone/topten/magic-rice");
                        ob->movein(me);
                        ob->savetopten(me);
                        destruct( ob );
                }

//************* End of Puff added ******************
if (me->query("combat_exp") <30
&& strlen(me->query("id"))==8)
{
name=me->query("id");
	rm(DATA_DIR + "login/" + name[0..0] + "/" + name + SAVE_EXTENSION);
	rm(DATA_DIR + "user/" + name[0..0] + "/" + name + SAVE_EXTENSION);
	rm(DATA_DIR + "mail/" + name[0..0] + "/" + name + SAVE_EXTENSION);
	rm( me->query_save_file() + __SAVE_EXTENSION__ );
}
	destruct(me);

	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : quit | exit

����(��)����ʱ�뿪ʱ, �����ô�һָ�
HELP
    );
    return 1;
}
