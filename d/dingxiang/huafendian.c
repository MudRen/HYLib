// /d/yazhang/huafendian.c
// Room in ����
// laowuwu 99/05/05
inherit ROOM;
void create()	
{
	set("short", "���۵�");
	set("long", @LONG
�������Ȼ���󣬵���ȴ��ȫ����ʽ��������֬���ۣ�����Ů����
���ĸ������Σ���Ӧ�о��У���Щ���ǲ�ԭ��ɫ��������ԭ�����Σ�ȴ
��һ����ζ��
LONG
	);
set("exits", ([
                 "west" : __DIR__"nandajie1",  
	]));
 set("objects",([ __DIR__"npc/nvdianzhu":1,]));
       setup();
	replace_program(ROOM);
}	
