// Room: /d/yanping/yanjindu.c
// Date: Sep 28, 2002  Winder

#include <ansi.h>
inherit ROOM;

void create()
{

  set("short", "�����");
  set("long", @LONG
��ƽ�ֳƽ��򡢽��֡��Ͻ��ݣ���Դ�ڽ�ʱ���۱�����˫��������
����ʷ��ʣ������顤�Ż������ء����׻���ǲʹ��һ���뻪����һ��
�壬�������ʧ�����ڡ����䣬�ӻ�Ϊ�ݴ��£��ֽ��о���ƽ������
��������׹ˮ��ʹ��ûˮȡ֮�������������������������ɣ��������
�£�û�߾���������ţ������ˮ�����˾��У����ǽ�ʧ�����˴�����
����֮����˫Ϫ�ڻ������ (river)����ӿ��ȥ��
LONG );
  set("exits", ([
    "northwest" : __DIR__"yanfumen",
//  "to" : "/d/fuzhou/matou",
  ]));
  set("no_clean_up", 0);
  set("outdoors", "yanping");
  set("coor/x", 1530);
  set("coor/y", -6200);
  set("coor/z", 10);


  setup();
}
