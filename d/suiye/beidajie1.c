// "suiye"/beidajie1
// Room in ��Ҷ
// laowuwu 99/03/28
inherit ROOM;
void create()	
{
	set("short", "�����");
	set("long", @LONG
�����·��խ��������һƥ�������������ĵ�·�ᴩ�ϱ���һ��
С�������ĵĽ����š�������Ǯׯ����������վ��
LONG
	);
set("outdoors", "suiye");
set("exits", ([
		"south":__DIR__"beidajie2",
		"north":__DIR__"beichengmen",
                "east":__DIR__"qianzhuang",
                "west":__DIR__"yizhan",
	]));
set("objects",([
"/clone/npc/man":1,
"/clone/misc/dache":1,	
	]));	
       setup();
	replace_program(ROOM);
}	
