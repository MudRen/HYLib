// Room: ɽ· 5
// bbb 1997/06/11
// Modify By River 98/12
inherit ROOM;
void create()
{
        set("short", "����ɽ·");
	set("long", @LONG
��������һ����᫲�ƽ��·��,��������ɭɭ��ԭʼ����,��ʱ����һ����
��Ұ�޽���, ͷ����һЩ��֪����С����������ȥ������һ��ɽ·�������죬
��֪��ͨ�����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	    "eastup" : __DIR__"xiaolu1",
	    "northdown" : __DIR__"xiaoxi",
        ]));
	set("no_clean_up", 0);
        set("outdoors", "����");

	setup();
}

int valid_leave(object me, string dir)
{
        if(dir=="eastup" ){
        if(me->query("can_ride")){
          return 0;
          }       
        if(me->query_temp("ride_horse"))
        return notify_fail("��ɽ��������\n");
        }
        return ::valid_leave(me, dir);
}
