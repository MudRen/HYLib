// baling/yaopu
// Room in ���� 
// laowuwu 99/04/11

inherit ROOM;

void create()
{
	set("short", "ҩ��");
	set("long", @LONG
����һ��ҩ�̣�һ��ŨŨ��ҩζ���㼸����Ϣ�����Ǵ�ҩ���ϵļ�
�ٸ�С������ɢ�������ġ�ҩ���ϰ����ڲ輸�ԣ����Ժ��Ų裬��Ҳ��
����һ�ۡ�һ��С���վ�ڹ�̨���к��Ź˿͡�
LONG
	);


	set("exits", ([
		"west" : __DIR__"beidajie1",
	]));
        set("objects",([
          __DIR__"npc/wang":1,
          ]));
	setup();
	replace_program(ROOM);
}

