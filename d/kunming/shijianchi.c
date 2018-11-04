// /d/kunming/shilin
// netkill /98/8/14/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW "�Խ���" NOR);
        set("long", @LONG
����һ��С��������С���������ɣ��м���һ���ʯ(stone)������ȥ
��Щ�Ź֡��ϱ��и�С��(dong)���ƺ��������ȥ��
LONG
        );
        set("outdoors", "kunming");
           
        setup();
        
}

void init()
{
	add_action("do_jump", "jump");
        add_action("do_zuan", "zuan");
        add_action("do_poke",  "poke");
}

int do_jump(string arg)
{  
	object me;
        int i_dodge;
        
        me=this_player();
        i_dodge=(int)me->query_skill("dodge");
        if (!arg || arg != "up") return 0;
        if (i_dodge < 100 ) return notify_fail("�������������˵̫����\n");
        else {   message("vision",
			"ֻ����Ӱһ��"+me->name() + "�ܲ�����������ȥ��\n",
			environment(me), ({me}) );
		 me->move(__DIR__"lianhua");
		 message("vision",
			"ֻ����Ӱһ��"+me->name() + "����������������\n",
			environment(me), ({me}) );
               message("vinson","����������һԾ���ڿ���ת������Ȧ���������嶥�ϡ�\n",me);
             }
	return 1;
}

int do_zuan( string arg)
{
	object me;
        me=this_player();
        if (!arg || arg !="dong") return 0;
        
        if ( me->query("gender") == "����" )
            return notify_fail("��һ�������ˣ��������ôС�Ķ���\n");
        if ( me->query("gender") == "����" )
            return notify_fail("��������������꣬��Ȼ�����������ֵط�һ�㶼����\n"+
                                "Ů�Ļ�ĵط������������ˣ����Ǳ�ȥ�ĺá�\n");
        if ( me->query("gender") == "Ů��" && (int)me->query("age")<25 )
            {	message("vision",
			me->name() + "һ�����������С����\n",
			environment(me), ({me}) );
		me->move(__DIR__"xiaodong");
		message("vision",
			me->name() + "�Ӵ��������˽�����\n",
			environment(me), ({me}) );
            message("vinson","��һ��������������ȥ�����ں�С���Һ�����Ů���ӣ�\n"+
                              "����С������ʲô�������ȥ�ˡ�\n",me);
            }else return notify_fail("����ô����ˣ���ô�������ôС�Ķ�\n");
        return 1;
}

int do_poke( string arg)
{       
	object me,weapon;
        int i_sword, i_qi;
        me=this_player();
        i_sword=(int)me->query_skill("sword",1);
	i_qi=600/(int)me->query("int");
        if (!arg || arg=="") return 0;
	if (arg == "stone")
		{ 
		if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("û�н�������\n");
	        if( (int)me->query("qi") < i_qi) return notify_fail("��̫���ˣ�����Ϣһ��ɡ�\n");
                if (i_sword < 20) 
			{message("vinson","��ͦ�����ʯ��ȥ����Ȼˮ�����������һ���ա�\n",me);
			 message("vision",
			 me->name() + "�����ų�����ƴ�����ʯͷ��ȥ��\n",
			 environment(me), ({me}) );}
	        if ( 20 <= i_sword && i_sword < 40) {
			message("vinson","��ͦ�����ʯ��ȥ����Ȼˮ���Ľ�����ֻ�̵��˵�ߡ�\n", me);
			message("vision",
			me->name() + "�����ų��������������ʯͷ��ȥ��\n",
			environment(me), ({me}) );}
		if ( 40 <= i_sword && i_sword < 60) {
                        message("vinson","��ͦ�������ʯ��ֻ������һ������Ľ�������֡�\n", me);
			message("vision",
			me->name() + "�����ų������ɿ�����ʯͷ��ȥ��\n",
			environment(me), ({me}) );}
		if ( 60 < i_sword) {message("vision",
			me->name() + "ͦ�������ʯ��ֻ���õ���һ��������û��ʯͷ����\n",
			environment(me), ({me}) );
			return notify_fail( HIW "��ͦ�������ʯ��ֻ���õ���һ��������û��ʯͷ����\n" NOR);}
		me->improve_skill("sword", 2*i_sword);
                me->receive_damage("qi", i_qi );
		}
        else return notify_fail("��Ҫ��ʲô��\n");
	return 1;	
}