// huayuan.c

inherit ROOM;

void create()
{
  set ("short", "��԰");
  set ("long", @LONG
��԰�л������࣬��Ժ�ӵ�����������һ��ӣ������ÿ��ӣ��ʢ����ʱ��
ƬƬӣ����ѩһ������ɲ�Ǻÿ�����԰��ǽ�Ե��е㰫�����峣������͵��
��ȥ�档
LONG);
set("item_desc",(["qiang":
"һ�°�ǽ��ǽ�ߵĲ��Ѿ����µ���Ŀȫ���ˣ�����\n"
]));
  set("outdoors", "feitian");
set("exits", ([ /* sizeof() == 4 */
"southwest" : __DIR__"chufang",
"northwest" : __DIR__"lianwuchang",
]));
	set("outdoors", 1);
        set("no_clean_up", 0);
        setup();
}

