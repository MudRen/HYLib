// /d/yazhang/huanggong.c
// Room in ����
// laowuwu 99/05/05
inherit ROOM;
void create()	
{
	set("short", "�ʹ�����");
	set("long", @LONG
�����Ƕ�ͻ�ʵĻʹ����ʹ���ڻԻͣ����Ĺ��Ž����ţ�������
��ͻ����ʿ�ᵶ�����������Żʹ��İ�ȫ�����˴������˶��Ƕ�ͻ�ʵ�
�߹ٴ�Ա��
LONG
	);
set("outdoors", "dingxiang");
set("exits", ([
                 "south" : __DIR__"beidajie1",
                 
	]));
	set("objects",([
	__DIR__"npc/kehan":1,
	__DIR__"npc/wujiang":3,	
	]));
       setup();
	replace_program(ROOM);
}	
