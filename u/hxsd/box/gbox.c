// ����

#include <ansi.h>
inherit ITEM;
int do_open(string arg);
string *box_object=({
"item/0",
"item/1",
"item/2",
"item/3",
"item/4",
"item/5",
"item/6",
"item/7",
"item/8",
"item/9",
"item/10",
"item/11",
"item/12",
"item/13",
"item/14",
"item/15",
"item/16",
"item/17",
"item/18",
"item/19",
"item/20",
"item/21",
"item/22",
"item/23",
"item/24",
"item/25",
"item/26",
"item/27",
"item/28",
"item/29",
"item/30",
"item/31",
"item/32",
"item/33",
"item/34",
"item/35",
"item/36",
"item/37",
"item/38",
"item/39",
"item/40",
"item/41",
"item/42",
"item/43",
"item/44",
"item/45",
"item/46",
"item/47",
"item/48",
"item/49",
"item/50",
"item/51",
"item/52",
"item/53",
"item/54",
"item/55",
"item/56",
"item/57",
"item/58",
"item/59",
"item/60",
"item/61",
"item/62",
"item/63",
"item/64",
"item/65",
"item/66",
"item/67",
"item/68",
"item/69",
"item/70",
"item/71",
"item/72",
"item/73",
"item/74",
"item/75",
"item/76",
"item/77",
"item/78",
"item/79",
"item/80",
"item/81",
"item/82",
"item/83",
"item/84",
"item/85",
"item/86",
"item/87",
"item/88",
"item/89",
"item/90",
"item/91",
"item/92",
"item/93",
"item/94",
"item/95",
"item/96",
"item/97",
"item/98",
"item/99",
"item/100",
"item/101",
"item/102",
"item/103",
"item/104",
"item/105",
"item/106",
"item/107",
"item/108",
"item/109",
"item/110",
"item/111",
"item/112",
"item/113",
"item/114",
"item/115",
"item/116",
"item/117",
"item/118",
"item/119",
"item/120",
"item/121",
"item/122",
"item/123",
"item/124",
"item/125",
"item/126",
"item/127",
"item/128",
"item/129",
"item/130",
"item/131",
"item/132",
"item/133",
"item/134",
"item/135",
"item/136",
"item/137",
"item/138",
"item/139",
"item/140",
"item/141",
"item/142",
"item/143",
"item/144",
"item/145",
"item/146",
});
             

void create()
{
	set_name(HIG"����"NOR, ({"bao xiang", "bao", "xiang"}));
        set("no_get",1);
	set_weight(100000);
	set_weight(10);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ���ú�ľ�������ɵ�"+HIG"���䣬"NOR+"�ƺ����Դ�(openbox)��\n");
		set("unit", "��");
		set("value", "20");
	}
}


void init()
{
   add_action("do_open","openbox");
}

   

int do_open(string arg)
{ 
    object me=this_player(),ob;
        if(me->query("gender")=="����")
    tell_object(me,"���Ȳ������ؽ�"+HIG+"����"NOR+"�򿪣�\n");
        else
    tell_object(me,"��С������ؽ�"+HIY+"����"NOR+"�򿪣�\n");

    if( me->over_encumbranced() )
    return notify_fail("���ϴ��Ķ���̫���ˣ��ò����ˡ�\n");

      if(random(100)>85)
      {
        tell_object(me,"���ʲôҲû�С�\n"NOR);
      }
      else if(random(100)>95)
      {
        ob=new("/clone/money/gold");
        ob->set_amount(random(100));
        ob->move(me);
        tell_object(me,"������һЩ"+HIY"�ƽ�"NOR+"��\n"NOR);
      }  
      else if(random(100)>95)
      {
        ob=new("/clone/money/gold");
        ob->set_amount(random(100));
        ob->move(me);
        tell_object(me,"������һЩ"+HIY"�ƽ�"NOR+"��\n"NOR);
      }  
      else if(random(200)>180)
      {
        me->add("jing",-50);
        me->add("qi",-100);
        tell_object(me,"�����﷢������"+HIR"����,��������!"NOR+"��\n"NOR);
      }  
      else if(random(200)>180)
      {
        me->add("jing",-50);
        me->add("qi",-100);
        tell_object(me,"�����﷢������"+HIR"����,��������!"NOR+"��\n"NOR);
      }  
      else if(random(200)>198)
      {
        me->apply_condition("snake_poison",10);
        me->add("qi",-10);
        tell_object(me,"�����﷢������"+RED"����,�����˶�!"NOR+"��\n"NOR);
      }  
      else if(random(200)>198)
      {
        me->apply_condition("wugong_poison",10);
        me->add("qi",-10);
        tell_object(me,"�����﷢������"+RED"����,�����˶�!"NOR+"��\n"NOR);
      }  
      else if(random(200)>198)
      {
        me->apply_condition("wugong_poison",10);
        me->add("qi",-10);
        tell_object(me,"�����﷢������"+RED"����,�����˶�!"NOR+"��\n"NOR);
      }  
      else if(random(200)>198)
      {
        me->apply_condition("zhizhu_poison",10);
        me->add("qi",-10);
        tell_object(me,"�����﷢������"+RED"����,�����˶�!"NOR+"��\n"NOR);
      }  
      else if(random(200)>198)
      {
        me->apply_condition("xiezi_poison",10);
        me->add("qi",-10);
        tell_object(me,"�����﷢������"+RED"����,�����˶�!"NOR+"��\n"NOR);
      }  
      else if(random(200)>198)
      {
        me->apply_condition("chanchu_poison",10);
        me->add("qi",-10);
        tell_object(me,"�����﷢������"+RED"����,�����˶�!"NOR+"��\n"NOR);
      }  
      else if(random(300)>298)
      {
        tell_object(me,"�����﷢��һ��"+HIY"����,��ʲôҲ��֪����!"NOR+"��\n"NOR);
        me->unconcious();
      }  
      else if(random(300)>298)
      {
        tell_object(me,"�����﷢��һ��"+HIR"���,��������鲻����!!"NOR+"��\n"NOR);
        me->die();
      }  

      else if(random(100)>95)
      {
        ob=new("/clone/money/silver");
        ob->set_amount(random(150));
        ob->move(me);
        tell_object(me,"������һЩ"+HIY"����"NOR+"��\n"NOR);
      }  
      else if(random(100)>95)
      {
        ob=new("/clone/money/silver");
        ob->set_amount(random(150));
        ob->move(me);
        tell_object(me,"������һЩ"+HIY"����"NOR+"��\n"NOR);
      }  
      else if(random(100)>95)
      {
        ob=new("/clone/money/silver");
        ob->set_amount(random(150));
        ob->move(me);
        tell_object(me,"������һЩ"+HIY"����"NOR+"��\n"NOR);
      }  
      else if(random(100)>95)
      {
        ob=new("/clone/money/coin");
        ob->set_amount(random(1000));
        ob->move(me);
        tell_object(me,"������һЩ"+HIY"ͭǮ"NOR+"��\n"NOR);
      }  
      else if(random(100)>95)
      {
        ob=new("/clone/money/coin");
        ob->set_amount(random(1000));
        ob->move(me);
        tell_object(me,"������һЩ"+HIY"ͭǮ"NOR+"��\n"NOR);
      }  
      else
      {
       int rand;
       rand=random(sizeof(box_object));
           ob=new(__DIR__+box_object[rand]);
        ob->move(me);
        tell_object(me,"������"+HIY":"+ob->query("name")+"."NOR+"��\n"NOR);
      }  
	destruct(this_object());         
        return 1;
}