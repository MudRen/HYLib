// /d/yazhang/beidajie2.c
// Room in ����
// laowuwu 99/05/05
inherit ROOM;
void create()	
{
	set("short", "�����");
	set("long", @LONG
�㼷����Ⱥ��������ʯ�Ľֵ��ϣ������߾������ʵ�ʮ�ֽֿڣ�
����һ���鱦�꣬���洫��һ��һʮ����Ǯ���������Ƿ�Բ��ʮ������
���һ��Ǯׯ��
LONG);
set("outdoors", "dingxiang");
set("exits", ([
                 "north" : __DIR__"beidajie1",  
                  "south" : __DIR__"guangchang",  
                  "east" : __DIR__"zhubaodian",  
                  "west" : __DIR__"qianzhuang",    
	]));
	set("objects",([
           __DIR__"npc/chunyuwei":1,
           ]));
       setup();
	replace_program(ROOM);
}	
