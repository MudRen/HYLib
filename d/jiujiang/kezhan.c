
inherit ROOM;


void create ()
{
  set ("short","�Ž����¥");
  set ("long", @LONG
���¥��ˮ䰴����е����ͷ���ν����ڴ��ⷴʫ����������
������Ϊ����ī�������Ž��ص�֮��������Ի�����ֽ��ݣ����Դ���
׮׮�У��ٴ��������޷�����Ӣ�۽�����׳־��ϸ��ˮ䰣��Ҿ�����
����棬ǧ��������������������ʷ׫���顣

LONG);

  set("exits", ([ 

 "north":__DIR__"dongdajie2",
 "enter":__DIR__"wofang",

         ]));
 set("objects",([
	 __DIR__"npc/xiaoer2":1,
	 ]));
 set("valid_startroom", 1);
  setup();
 
}

int valid_leave(object me,string dir)
{
	if(!me->query_temp("gived_money")&&dir=="enter")
		if(objectp(present("xiao",environment(me))))
			return notify_fail("��С����ס���㣺�͹٣�����û��Ǯ��!\n");
		else return notify_fail("�ƹ�����溰�����͹٣���Ǯ��ס�갡!\n");
		return ::valid_leave(me,dir);
		return 1;
}
