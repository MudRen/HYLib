// "suiye"/shudian
// Room in ��Ҷ
// laowuwu 99/03/28
inherit ROOM;
void create()	
{
	set("short", "���");
	set("long", @LONG
������һ��������ķ��䣬ֻ���ı���������ܣ�����ϵ��鼮
�����Ӱټҵ��Դʸ踳����ȫ�ס����䵱����һ�򵥵����������ϰڷ�
�ŵı�īֽ����һ���Ǿ�Ʒ������ǽ��������һ���ֻ���������Ů����
�����ƻ�������
LONG
	);
set("exits", ([		
                "east"  : __DIR__"nandajie2",                
	]));
	set("objects",([
	__DIR__"npc/li":1,
	]));
       setup();
	replace_program(ROOM);
}	
