//shanlu1.c
inherit ROOM;

void create()
{
  set("short","�����߳�");
	set("long", @LONG
���ǰ���ɽׯ�������߳������߹Ȳ�׽���Ķ��߶��ڴ���������
��Χ���������ߵĻ�ɫԲǽ��ǽ������Բ���Σ��⻬�޷졣���ｨ��
������ѣ��ɰ���ɽׯ�е���ū����������綾�Ĺ��߾����ڴ�
�ӽ����á�
LONG
	);
  set("exits",([
      "east" : "/d/baituo/caomeide",
     ]));
  set("outdoors", "baituo");
//  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}

