// Room: /d/menggu/caoyuan6
inherit ROOM;

void create()
{
  set ("short", "��ľ�沿��");
  set ("long", @LONG
��ľ�沿���ǵ����ɹŲ�ԭ����ǿʢ��һ��,������������ı,������
��,��ԭ�ϵ�Ӣ�۶�Ը��Ϊ��Ч��,��Ŀ������֮��,ţ����׳,������ɹ�
���ڸ��˾�Ŀ���������Ĳ�ԭ.
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"buluo",
  "west" : __DIR__"shulin1",
  "southwest" : __DIR__"caoyuan5",
]));
  set("outdoors", "menggu");
  setup();
  replace_program(ROOM);
}
