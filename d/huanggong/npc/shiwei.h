void init()
{
 object ob;
 ::init();
 if (interactive(ob=this_player())&&!is_fighting()) {
   remove_call_out("greeting");
   call_out("greeting",1,ob);
   }
 }
void greeting(object ob)
{
 if (!ob||environment(ob)!=environment()) return;
 if (!ob->query_temp("huanggon/enter")&&ob->query("gender")!="����")
    {
if (ob->query("xxy/lvl")<4) {
    command("say �󵨿�ͽ,�����ô��ʹ�.\n");
    kill_ob(ob);
}
    return;
  }
 if (ob->query("gender")=="����"&&ob->query("combat_exp")>500000)  {
 	command("say "+name()+"����"+ob->query("name")+"����.\n");
    } 
  return;
 }
