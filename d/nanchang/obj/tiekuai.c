

inherit ITEM;

void create()
{
   set_name("����", ({ "tie kuai","tie","kuai"}) );
   set_weight(6000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "iron");
	 set("long","����һ�����飬���������������������\n");
     set("unit", "��");
     set("value", 1000);
	 set("weapon",([
		 "damage":30,
		 "strong":80,
		 ]));
    
   }
   setup();
}
