// "suiye"/jiyuan
// Room in ��Ҷ
// laowuwu 99/03/28
inherit ROOM;
void create()	
{
	set("short", "��Ժ");
	set("long", @LONG
����������С�������Ŵ�Ϣ����СС����Ҷֻ�����ﻹ�������֣�
�������������Ϊһ�������Ĺ��ﲻ�ϽӿͶ������أ��깫������ò�
��̧ͷ����Ժ��һ����Ժ����ʱ����һ������Ц��
LONG
	);
set("exits", ([
		
               
               "eastdown" :__DIR__"houyuan",
                "west": __DIR__"nandajie2",
       ]));
 set("objects",([ __DIR__"npc/girl2":1,]));
       setup();
	replace_program(ROOM);
}	
