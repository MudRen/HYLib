//�캮ɽ
// by steel 

inherit ROOM;

void create()
{
	set("short", "�캮ɽ��");
	set("long", @LONG
	���Գ������˵����������˰�ɽ�������˶�����ɽ����ȥ��ֻ
��������⣬��һ����װ�ع��ľ���    
LONG
	);
	
       set("exits", ([
		"northup" : __DIR__"hill2",
		"southdown" : __DIR__"hill",
	]));
	setup();
}

int valid_leave(object me,string dir)
{
        if(dir=="northup")
        {
         if((int)me->query_skill("dodge",1)<=70)
           {
         me->add("jing",-50);
         me->add("qi",-50);
          }
          else{
          me->add("jing",-30);
          me->add("qi",-30);
          } 
        } 
     return 1;     
}   
