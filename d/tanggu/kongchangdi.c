#include <ansi.h>
inherit ROOM;
string look_leitai();
string look_qi();
string look_board();

void create()
{
        set("short", HIY"�㳡�յ�"NOR);
        set("long", "�˴�������������֮����ֻ����¥�����廧���ţ��񳵾�פ���������ۡ�һ
Ƭ�����ĳ����ϣ�������ǰ�������������Ȳ�֮�������ڶ���ԶԶ��ȥ��Χ�źô�
һ���ˣ�ֻ���м��ϴ�һ��յأ�����һ��"NOR+HIR"��̨"NOR+"�����²���һ����죨Qi�����׵�
�컨�����š�"NOR+HIY"���� ����"NOR+"���ĸ����֣�����һ��װ壨Board����������������ȭ��
��ȥ�Ĵ�����֣�һ���Ǻ�����Ů��һ���ǳ����ӡ�\n");

        set("no_fight", 1);
        set("no_sleep_room", 1);
        set("leitai", __DIR__"biwuleitai");
        set("exits", ([ 
			             "northwest" : "/d/tanggu/center",
        ])); 
        set("objects", ([    
             	//__DIR__"npc/mu-nianci" : 1,
				//__DIR__"npc/manghan" : 1,
        ]));
        set("item_desc",([            
            "qi" : (: look_qi :),
				"leitai" : (: look_leitai :),
				"board" : (: look_board :),
        ]));
        set("outdoors", "����");  
        setup(); 
}


string look_qi()
{
    	object me,obj,who;
		string str;
		int i,p;
    	me = this_player();
    	if (me->is_busy()) 
          	return "����æ���ء�\n";
    	me->start_busy(2);
		str  = "һ����죬�׵׺컨�����š�"+HIY"��������"NOR+"�������¼���С�֣�\n\n";
		str += "        ��"+HIC"�Ի������أ�����������"NOR+"��\n\n";
		obj=present("mu nianci",this_object());
		if(obj && obj->query("station") && obj->query("bwzh/host_player"))
		{
			who=obj->query("bwzh/host_player/object");
			if(!who) return "";
			i=who->query("age")-obj->query("bwzh/age");
			if(i<18) i=18;
			p=who->query("age")+obj->query("bwzh/age");
			if(p>80) p=80;
			str += HIC"�ڽ���Ĳ���һ�ǣ�д��һ�����֣�"+obj->query("bwzh/host_player/name")+"��\n"NOR;
			str += HIC"��������ע���������֣�"+obj->query("bwzh/exp")+"|"+obj->query("bwzh/per")+"|"+i+"|"+p+"��\n"NOR;
		}
        tell_object(me,str);
    	return "";
}
string look_board()
{
    	object me,obj;
		string str;
    	me = this_player();
    	if (me->is_busy()) 
          	return "����æ���ء�\n";

    	me->start_busy(2);
		obj=present("mu nianci",this_object());
		if(!obj || !obj->query("bwzh/winner_player"))
		{
			str  = "һ��װ壬���Ϸ�д�š�"+HIY"��������"NOR+"�����⣬����ȴʲôҲûд��\n";
		}
		else
		{
			if(obj->query("bwzh/challenge_player"))
				str  = "һ��װ壬���Ϸ�д�š�"+HIY"��������"NOR+"�����⣬����Ҳд�������֣�\n";
			else 
				str  = "һ��װ壬���Ϸ�д�š�"+HIY"��������"NOR+"�����⣬����Ҳд��һ���֣�\n";

			str += "\n             ��"+HIC"��  ��"NOR+"����"+obj->query("bwzh/winner_player/name")+"\n";
			if(obj->query("bwzh/challenge_player"))
				str += "             ��"+HIC"��ս��"NOR+"����"+obj->query("bwzh/challenge_player/name")+"\n";
		}
        tell_object(me,str);
    	return "";
}




