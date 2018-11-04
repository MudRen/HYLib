// CMDS USR news.c
// Created by kittt@DJX2000
// Last Modified by kittt@DJX 6/2/2000
//
// XKX ������˽������Ϣһ������ Help Whatsnew
// �����ʦ�ڸ��º���Ҫ��д/doc/help/�ļ����ܲ����㡣
// �������������ϵͳ������������Ϣֻ����POSTһ����
// Ҳ������������Ķ�����Ҳ�ȽϷ��㡣


#include <ansi.h>;
inherit BULLETIN_BOARD;

// create part����ͨ��BOARD���
void create()
{
	set_name("����II���Ű�", ({ "newsboard"}) );
	set("location", "/d/wizard/proom"); // ��������һ��ROOM������BOARD���򵥣����� 
	set("board_id", "hy2news_b");              // ��һ��ָ������������Ҳ���ԡ�
	setup();
	set("capacity", 500);
}

// ���������������loginʱ���õġ�
int check_news(object me)
{
	int num,i,last_time_read;
	mapping *notes, last_read_time;
	string myid,msg="";
	
	notes = query("notes");
	last_read_time = me->query("board_last_read");
	myid = query("board_id");
	
	if( !pointerp(notes) || !sizeof(notes) ) return 1;

 	if(userp(me))
	{
		i=sizeof(notes)-me->query("LastReadNews");
		
		if(i < 6 && i > 0) // С��6�����Ų���ʾ���⣬��Ȼ��FLOOD
		{
			msg = "\n\n    ������������������������ "HIW"����II������Ϣ"NOR" ������������������������    \n";
			
			if( !mapp(last_read_time) || undefinedp(last_read_time[myid]) )
				num = 1;
				
			else
				for(num = 1; num<=sizeof(notes); num++)
					if( notes[num-1]["time"] > last_read_time[myid] ) break;
					
			if (mapp(last_read_time)) last_time_read = last_read_time[myid];
			for(i=sizeof(notes)-1 ; i>num-2 ; i--)
			{
				msg += sprintf("<%3d>"NOR,i+1);
				msg += sprintf("     %-=36s %18s (%s)\n",
					notes[i]["title"], notes[i]["author"],
					CHINESE_D->chinese_time(5, ctime(notes[i]["time"])));
			}
			
			msg += "    ����������������������������������������������������������������    \n\n";
			
			me->start_more(msg);
		}
		
		i=sizeof(notes)-me->query("LastReadNews");
		
		write("\n�����ϴ��Ķ�������"+((i==0)? "û���κ�":"����"+HIY+chinese_number(i)+NOR"��")+"���š�\n\n");
		if(i>10) write("����� Help news ���鿴����Ц����ϵͳ��ʹ�÷�����\n"); // ���Ѳ�֪����NEWSϵͳ�����ʹ��news
	}
}

int main(object me, string arg)
{
	int num,i,last_time_read;
	mapping *notes, last_read_time;
	string myid,msg;

	last_read_time = me->query("board_last_read");
	myid = query("board_id");
	notes = query("notes");
	i=sizeof(notes)-me->query("LastReadNews");
	if( !pointerp(notes) || !sizeof(notes) )
		return notify_fail("������II��Ŀǰû���κ����š�\n");
		
	if( !arg ) 
	{
		if(i>10) write("����� Help news ���鿴����Ц����ϵͳ��ʹ�÷�����\n"); 
			return notify_fail(
				"������II��Ŀǰ����"+HIW+chinese_number(sizeof(notes))+NOR"������"+((i==0)? "��":"������"+HIY+chinese_number(i)+NOR"��������δ�Ķ���")+"\n"); }
				
		if( arg=="all") // ��ʾ��������
		{
			msg = "\n\n    ������������������������ "HIW"����Ц����һ��"NOR" ������������������������    \n";
			notes = query("notes");
			
			if (mapp(last_read_time)) last_time_read = last_read_time[myid];
			for(i=sizeof(notes)-1 ; i>-1 ; i--)
			{
				msg += sprintf("%s<%3d>" NOR,
				notes[i]["time"] > last_time_read ? HIY: "", i+1);
				msg += sprintf("     %-=36s %18s (%s)\n",
					notes[i]["title"], notes[i]["author"],
					CHINESE_D->chinese_time(5, ctime(notes[num]["time"])));
			}
			msg += "\n";
			me->start_more(msg);
			return 1;
			
		}
		else
		if ( arg=="new" )  // ��ʾ��������
		{
			if( !mapp(last_read_time) || undefinedp(last_read_time[myid]) )
				num = 1;
			else
				for(num = 1; num<=sizeof(notes); num++)
					if( notes[num-1]["time"] > last_read_time[myid] ) break;
					
		} else if( !sscanf(arg, "%d", num) )
		
	return notify_fail("�㵽��Ҫ���ڼ�������ѽ��\n");
	
	if( num < 1 || num > sizeof(notes) )
		return notify_fail("������㣬����û����������Ү��\n");
		
	num--;
	me->start_more( sprintf("\n\n%s\n"HIR"�������⣺"HIY"%s\n"HIW"������ʦ��"NOR"%s\n"HIG"����ʱ�䣺%s\n"NOR
	"-------------------------------------------------------------------------------\n",
		BBLU HIG"��"HIR"��"HIY"��"HIW"II"HIG"����"+chinese_number(num + 1)+"������"NOR, 
		notes[num]["title"], notes[num]["author"],
		CHINESE_D->chinese_time(5, ctime(notes[num]["time"])))
		+ notes[num]["msg"]+
	"-------------------------------------------------------------------------------\n\n", );

	if( !mapp(last_read_time) )
		me->set("board_last_read", ([ myid: notes[num]["time"] ]) );
	else 
		if( undefinedp(last_read_time[myid]) || notes[num]["time"] > last_read_time[myid] )
			last_read_time[myid] = notes[num]["time"];

	if(me->query("LastReadNews") < num + 1)
		me->set("LastReadNews",num+1);

	return 1;
}

void init()
{
	object me=this_player();
// ֻ��apprentice�������ϵ���ʦ�޸�����
       if (wizardp(me) &&  wiz_level(me) > wiz_level("(apprentice)") )
	{
		add_action("do_post", "post");
		add_action("do_discard", "discard");
      }	
}

/* ������ݿ��ܴ󲿷ݵ�MUD������Ҫ
   ����������Ϊֻ�����޸���DJX��bboard��һЩ�ط����ˡ�   
int do_post(string arg)
{
	mapping note;

	if(!arg) return notify_fail("����Ҫ������Ŀ��\n");

	note = allocate_mapping(4);
	note["title"] = arg;
      note["author"] = this_player()->query("name")+"("+this_player()->query("id")+")";
	note["id"] = this_player()->query("id"); 
	this_player()->edit( (: done_post, this_player(), note :) );
	return 1;
}
*/

void done_post(object me, mapping note, string text)
{
	mapping *notes;

	note["time"] = time();
	note["msg"] = text;
	notes = query("notes");
	if( !pointerp(notes) || !sizeof(notes) )
		notes = ({ note });
	else
		notes += ({ note });

	if( sizeof(notes) > query("capacity"))
		notes = notes[query("capacity")/2 .. query("capacity")];

	set("notes", notes);
	save();
	restore();
// ʹ��channel��ʾ��ʾ������������
	CHANNEL_D->do_channel(me, "news", BLINK HIY"\n������II�������������ţ����� news �鿴��\n\n" NOR);

	tell_object(me, "���ŷ�����ϡ�\n");

	return;
}

int help(object me)
{
    write(@HELP
������II������ϵͳָ�� 

ָ���ʽ :
news                    �鿴���еĺ����·��������š�
news all                ����II����һ���� 
news new                �Ķ����µ����š� 
news <���ű��>         �鿴�˱�����ŵ���ϸ���ݡ� 
HELP
    );
    return 1;
}
