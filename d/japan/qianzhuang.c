// Room: /d/japan/qianzhuang.c

inherit ROOM;

void create()
{
	set("short", "Ǯׯ");
	set("long", @LONG
Ǯׯ���ϰ��Ǹ�ͺ���Դ��ļһ�,���ڷŸ�����������,���ǮҪ�Ǵ�
������Ǯׯ,����Ҫ�ձ��ܷ��õ�.���������ڸ���������ϵ.����ʵ��ͨ��
ͨ��,��ȻҪ��һ��������.
    �ڶ����ǽ�Ϲ��˿�����(paizi)��
LONG
	);
	set("item_desc", ([
		"paizi" : @TEXT
     ��Ǯׯ�ṩ���·���
      ��Ǯ        deposit����cun
      ȡǮ        withdraw����qu
      Ǯ�Ҷһ�    convert����duihuan
      ����        check����chazhang
TEXT
	]) );
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"jiedaos",
]));
        set("objects", ([ /* sizeof() == 1 */
               __DIR__"npc/xiaye" : 1,
            ]));
	set("no_clean_up", 0);
	set("no_clean_up", 0);
	set("no_fight", 1);
	set("no_beg", 1);
	setup();
	replace_program(ROOM);
}
