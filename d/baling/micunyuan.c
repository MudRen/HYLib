// baling/nandajie3
// Room in ���� 
// laowuwu 99/04/11
inherit ROOM;

void create()
{
	set("short", "�ٴ�Ժ");
	set("long", @LONG
�����󣬵��������֣��ö๫����ү��������깫���ź��š�ǽ
�Ϲ�������Ѱ��ͼ������Ц֮����¥�ϴ�������ʱ��������һ������
���ޱ��˷ܵ��������㲻�������ļӿ��˲�����
LONG
	);
        set("outdoors", "baling");

	set("exits", ([
		"westdown":__DIR__"nandajie2",
                "up":__DIR__"xunhuange",
	]));
	setup();
	
}

int valid_leave(object ob,string dir)
{
  if(ob->query("age")<18&&dir=="up"&&!wizardp(ob))
  return notify_fail("С���ӻ��ǲ�Ҫ�����ֵط�ȥ��\n");
  return ::valid_leave(ob,dir);
}
