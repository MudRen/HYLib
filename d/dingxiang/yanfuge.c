// /d/yazhang/yanfuge.c
// Room in ����
// laowuwu 99/05/05
inherit ROOM;
void create()	
{
	set("short", "�޸���");
	set("long", @LONG
���Ų��߽��޸���Ĵ����������������õļ�������ݳޣ�һ����
֪��������ͨ�����������ĵط����⵱ǰ��һ����ʯ������Բ�����ͨ
�ٻ��˼����������ġ���ӭ���ǽ���Ϲ���һ�����������۲׺���Ϊ
ˮ����ȴ��ɽ�����ơ������������֣����޸��󡱡�
LONG
	);
set("exits", ([
                  "north" : __DIR__"xidajie1",  
	]));
       setup();
	replace_program(ROOM);
}	
