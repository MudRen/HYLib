// /d/taiyuan/shuifang.c
// Room in ̫ԭ
// rich 99/05/05
inherit ROOM;
void create()	
{
	set("short", "˯��");
	set("long", @LONG
����һ��ʮ����ͨ��˯�������ﲼ�õķǳ��򵥣�ֻ��һ�Ŵ���һ
�ŷ���������Բ�ʣ���ȴʮ���ľ������Ѿ������ˣ����ڴ��ϣ����˯
ȥ��
LONG
	);
set("exits", ([
                "north" : __DIR__"guobingguan", 
	]));
	set("sleep_room",1);
       setup();
	
}	

int valid_leave(object ob,string dir)
{
  if(dir=="north")
  ob->delete_temp("gived_money");
  return ::valid_leave(ob,dir);
}