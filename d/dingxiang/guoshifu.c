// /d/yazhang/guoshifu.c
// Room in ����
// laowuwu 99/05/05
inherit ROOM;
void create()	
{
	set("short", "��ʦ��");
	set("long", @LONG
�����Ƕ�ͻ�ʹ�ʦ�ĸ��أ����ϵı��ǻ������͵ģ���̧ͷ��ȥ��
����ʦ������������ӳ��������
LONG
	);
set("outdoors", "dingxiang");
set("exits", ([
                   "south" : __DIR__"xidajie2",  
"northwest":__DIR__"yizhan",
	]));
	set("objects",([
	__DIR__"npc/bi":1,
	]));
       setup();
	replace_program(ROOM);
}	
