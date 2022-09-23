/* Copyright (c) 2017, United States Government, as represented by the
 * Administrator of the National Aeronautics and Space Administration.
 *
 * All rights reserved.
 *
 * The Astrobee platform is licensed under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with the
 * License. You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations
 * under the License.
 */

#ifndef GRAPH_LOCALIZER_SEMANTIC_LOC_GRAPH_ACTION_COMPLETER_H_
#define GRAPH_LOCALIZER_SEMANTIC_LOC_GRAPH_ACTION_COMPLETER_H_

#include <graph_localizer/combined_nav_state_graph_values.h>
#include <graph_localizer/semantic_loc_factor_adder_params.h>
#include <graph_optimizer/graph_action_completer.h>
#include <graph_optimizer/graph_action_completer_type.h>

namespace graph_localizer {
class SemanticLocGraphActionCompleter : public graph_optimizer::GraphActionCompleter {
 public:
  SemanticLocGraphActionCompleter(const SemanticLocFactorAdderParams& params,
                                  const graph_optimizer::GraphActionCompleterType graph_action_completer_type,
                                  std::shared_ptr<CombinedNavStateGraphValues> graph_values);

  bool DoAction(graph_optimizer::FactorsToAdd& factors_to_add, gtsam::NonlinearFactorGraph& graph_factors) final;

  graph_optimizer::GraphActionCompleterType type() const final;

 private:
  SemanticLocFactorAdderParams params_;
  graph_optimizer::GraphActionCompleterType graph_action_completer_type_;
  std::shared_ptr<CombinedNavStateGraphValues> graph_values_;
};
}  // namespace graph_localizer

#endif  // GRAPH_LOCALIZER_SEMANTIC_LOC_GRAPH_ACTION_COMPLETER_H_