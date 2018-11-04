// Room: /u/keinxin/workroom.c

#include <ansi.h>
inherit ROOM;
string look_hua();
string look_duilian();
string clear_title(string arg);
void add_title(object me,string arg);
void create()
{
	set("short", "���콣ի");
	set("long", @LONG
������ǡ��齣�����д�˵�ķ��콣ի������꽣�����ӵĵط�������������Ϸ���
��������������ľ���ѧ������ǽ�Ϲ���һ����(hua)��������һ������(duilian)��
���ӵ����������һ���Ϲ�ʯ����          
LONG );

	set("item_desc", ([ 
	"hua" : (: look_hua :),
        "duilian" : (: look_duilian :),
	]));
	set("exits", ([ 
	 	"gc": "/d/city/guangchang"
	]));

        set("objects", ([
        "/u/keinxin/jinyong" : 1 ]) );

        set("no_fight", "1");
	set("no_clean_up", 0);
	setup();
}
string look_hua()
{
       return 
"\n       
"HIY"��������2002��6��19��

\n"NOR;
}
string look_duilian()
{
	return
"\n	
"HIY"
              ����                ����
              *��*                *��*  
              *��*                *��*
              *��*                *��*
              *ҵ*                *��* 
              *Ц*                *һ*
              *̸*                *��* 
              *��*                *��* 
              ����                ���� 
\n"NOR;           
}

